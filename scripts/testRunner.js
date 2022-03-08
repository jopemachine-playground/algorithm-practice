import path from 'node:path';
import fs from 'node:fs';
import {execaCommand} from 'execa';
import {globby} from 'globby';
import chalk from 'chalk';
import logSymbols from 'log-symbols';
import {pathExists} from 'path-exists';

const fsp = fs.promises;

const run = async testNumber => {
	const paths = await globby('tests/*');
	try {
		await execaCommand('g++ -std=gnu++17 t.cpp');
	} catch (error) {
		console.log(chalk.red(`${logSymbols.error} Compile Failed!`));
		console.log(error.stderr);
		process.exit(1);
	}

	if (paths.length === 0) {
		console.error(`${logSymbols.error} There are no test cases`);
		process.exit(1);
	}

	let idx = 1;
	const result = [];
	for (const testFilePath of paths) {
		if (testNumber && testNumber != idx) {
			++idx;
			continue;
		}

		const filename = path.parse(testFilePath).base;
		const content = await fsp.readFile(testFilePath, {encoding: 'utf-8'});
		await fsp.writeFile('input', content, {encoding: 'utf-8'});

		console.log(chalk.gray(`-------------- Test case ${idx} --------------`));
		let stdout; let stderr;

		try {
			const res = await execaCommand('./a.out');
			stdout = res.stdout ?? '';
			stderr = res.stderr ?? '';
		} catch (error) {
			console.log(chalk.red(`${logSymbols.error} Runtime error!`));
			console.log(error.shortMessage);
			++idx;
			continue;
		}

		if (stderr) {
			console.log(chalk.gray(`${logSymbols.info} [DEBUG]: `, stderr));
		}

		const answerPath = path.resolve(`answers/${filename}`);
		if (await pathExists(answerPath)) {
			const expected = (await fsp.readFile(answerPath, {encoding: 'utf-8'})).trim();
			if (stdout.trim() === expected) {
				result.push(chalk.greenBright(`${logSymbols.success} Test ${idx} Success!`));
			} else {
				result.push(chalk.red(`${logSymbols.error} Test ${idx} Failed!`));
			}
		}

		console.log(stdout);

		if (!stdout) {
			console.log(chalk.gray('stdout is empty!'));
		}

		++idx;
	}

	if (result.length > 0) {
		console.log(chalk.gray('\n-----------------------------------------'));
		console.log(chalk.gray('* Test Result\n'));
		console.log(result.map(e => ' ' + e).join('\n'));
		console.log();
	}
};

export {
	run,
};
