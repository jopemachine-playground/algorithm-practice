import fs from 'node:fs';
import process from 'node:process';
import path from 'node:path';
import {unusedFilename} from 'unused-filename';
import chalk from 'chalk';
import open from 'open';
import got from 'got';
import {load} from 'cheerio';
import {globby} from 'globby';
import logSymbols from 'log-symbols';
import inquirer from 'inquirer';

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

const fetchTests = async problemNumber => {
	const res = await got(`https://www.acmicpc.net/problem/${problemNumber}`);
	await clearTests();

	const $ = load(res.body);

	for (let i = 1; ; ++i) {
		const sampleInput = $(`#sample-input-${i}`);
		const sampleOutput = $(`#sample-output-${i}`);
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

const setProblem = async () => {
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

	console.log(`${logSymbols.success} Set problem path successfully: '${paths[0]}'`);
	const execFileContent = await fsp.readFile('t.cpp', {encoding: 'utf-8'});
	const [_, ...content] = execFileContent.split('\n');

	await fsp.writeFile('t.cpp', [
		`#include "${paths[0]}"`,
		...content,
	].join('\n'), {encoding: 'utf-8'});
};

const createProblem = async problemNumber => {
	let paths = await globby('Baekjoon-Algorithm/*', {onlyDirectories: true});

	await inquirer
		.prompt([
			{
				type: 'list',
				name: 'file',
				message: chalk.dim('Select an folder to save the file'),
				choices: paths.map(path => ({name: path, value: path})),
			},
		])
		.then(selection => {
			paths = [selection.file];
		});

	const pathToSave = path.resolve(paths[0], [problemNumber, config.get('extension')].join('.'));
	const template = await fsp.readFile(path.resolve(config.get('template')), {encoding: 'utf-8'});

	const commentTemplate = await fsp.readFile(path.resolve(config.get('template')), {encoding: 'utf-8'});

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