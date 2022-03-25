import fs from 'node:fs';
import process from 'node:process';
import path from 'node:path';
import {unusedFilename, separatorIncrementer} from 'unused-filename';
import chalk from 'chalk';
import {execa, execaCommand} from 'execa';
import open from 'open';
import got from 'got';
import {load} from 'cheerio';
import {globby} from 'globby';
import logSymbols from 'log-symbols';
import inquirer from 'inquirer';
import inquirerAutocompletePrompt from 'inquirer-autocomplete-prompt';

import {config} from './conf.js';

const fsp = fs.promises;

const addTest = async copiedTexts => {
	console.log(chalk.gray('Added test:\n\n') + chalk.white(`${copiedTexts}\n`));
	await fsp.writeFile(await unusedFilename('tests/input'), copiedTexts, {
		encoding: 'utf-8',
	});
};

const addAnswer = async copiedTexts => {
	console.log(chalk.gray('Added answer:\n\n') + chalk.white(`${copiedTexts}\n`));
	await fsp.writeFile(await unusedFilename('answers/input'), copiedTexts, {
		encoding: 'utf-8',
	});
};

const clearTests = async () => {
	await fsp.rm('tests', {recursive: true, force: true});
	await fsp.rm('answers', {recursive: true, force: true});
	await fsp.mkdir('tests');
	await fsp.mkdir('answers');
};

const openProblem = async problemNumber => {
	open(`https://www.acmicpc.net/problem/${problemNumber}`, {wait: false});
};

let problemInfo;
const fetchProblemInfo = async problemNumber => {
	const res = await got(`https://www.acmicpc.net/problem/${problemNumber}`);
	problemInfo = load(res.body);
	return problemInfo;
};

const fetchProblemAttributes = async problemNumber => {
	if (!problemInfo) {
		await fetchProblemInfo(problemNumber);
	}

	return {
		title: problemInfo('#problem_title').text(),
		// 알고리즘 분류 작동 안 됨.
		// kind: problemInfo('.spoiler-link'),
	};
};

const fetchTests = async problemNumber => {
	if (!problemInfo) {
		await fetchProblemInfo(problemNumber);
	}

	await clearTests();

	for (let i = 1; ; ++i) {
		const sampleInput = problemInfo(`#sample-input-${i}`);
		const sampleOutput = problemInfo(`#sample-output-${i}`);
		const sampleInputTxt = sampleInput.text();
		const sampleOutputTxt = sampleOutput.text();

		if (!sampleInputTxt || !sampleOutputTxt) {
			break;
		}

		await addTest(sampleInputTxt);
		await addAnswer(sampleOutputTxt);
	}
};

const commitProblem = async problemNumber => {
	let paths = await globby(`**/${problemNumber}*.*`);

	if (paths.length === 0) {
		console.error(`${logSymbols.error} Failed to find '${problemNumber}'`);
		process.exit(1);
	}

	if (paths.length > 1) {
		await inquirer
			.prompt([
				{
					type: 'list',
					name: 'file',
					message: chalk.dim('Choose file to commit'),
					choices: paths.map(path => ({name: path, value: path})),
				},
			])
			.then(selection => {
				paths = [selection.file];
			});
	}

	const {dir} = path.parse(paths[0]);
	await execa('git', ['add', paths[0]]);
	await execa('git', ['commit', '-m', `[${dir}] Solve ${problemNumber}`]);
	await execaCommand('git push origin master');
	console.log(`${logSymbols.success} Commit and push problem successfully: '${paths[0]}'`);
};

const setProblem = async problemNumber => {
	let paths = await globby(`**/${problemNumber}*.*`);

	if (paths.length === 0) {
		console.error(`${logSymbols.error} Failed to find '${problemNumber}'`);
		process.exit(1);
	}

	if (paths.length > 1) {
		await inquirer
			.prompt([
				{
					type: 'list',
					name: 'file',
					message: chalk.dim('Choose file to set'),
					choices: paths.map(path => ({name: path, value: path})),
				},
			])
			.then(selection => {
				paths = [selection.file];
			});
	}

	console.log(`${logSymbols.success} Set problem path successfully: '${paths[0]}'`);
	const execFileContent = await fsp.readFile('t.cpp', {encoding: 'utf-8'});
	const [_, ...content] = execFileContent.split('\n');

	await fsp.writeFile('t.cpp', [
		`#include "${paths[0]}"`,
		...content,
	].join('\n'), {encoding: 'utf-8'});
};

const searchProblemTags = (paths, input) => {
  return paths.filter(path => !input || path.includes(input)).map(path => ({
    name: path.split('Baekjoon-Algorithm/')[1],
    value: path,
  }));
};

const createProblem = async problemNumber => {
  let paths = await globby('Baekjoon-Algorithm/**/*', {
    onlyDirectories: true,
	});

  inquirer.registerPrompt('autocomplete', inquirerAutocompletePrompt);

  paths = [(await inquirer.prompt([{
		name: 'folder',
		message: 'Select an folder to save the file',
		type: 'autocomplete',
		pageSize: 10,
		source: async (answers, input) => searchProblemTags(paths, input),
	}])).folder];

	const {title} = await fetchProblemAttributes(problemNumber);

  const prefixIncrementer = (filename, extension) => {
    const match = filename.match(/^(?<index>\d+)_(?<originalFilename>.*)$/);
    let {originalFilename, index} = match ? match.groups : {originalFilename: filename, index: 1};
    originalFilename = originalFilename.trim();
    return [`${originalFilename}${extension}`, `${originalFilename}_${++index}${extension}`];
  };

	const pathToSave = await unusedFilename(
		path.resolve(paths[0], [problemNumber, config.get('extension')].join('.'))
		, {
      incrementer: prefixIncrementer,
    });

	const template = await fsp.readFile(path.resolve(config.get('template')), {encoding: 'utf-8'});
	const commentTemplate = (await fsp.readFile(path.resolve(config.get('commentTemplate')), {encoding: 'utf-8'}))
		.replace('{problemTitle}', title);

	await fsp.writeFile(pathToSave, `${commentTemplate}\n${template}`, {encoding: 'utf-8'});

	await setProblem(problemNumber);
	await fetchTests(problemNumber);
};

export {
	addTest,
	addAnswer,
	clearTests,
	fetchTests,
	openProblem,
	commitProblem,
	createProblem,
	setProblem,
};

export {run} from './testRunner.js';
