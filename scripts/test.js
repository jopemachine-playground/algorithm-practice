import {execaCommand} from 'execa';
import {globby} from 'globby';
import chalk from 'chalk';
import logSymbols from 'log-symbols';
import {pathExists} from 'path-exists';
import boxen from 'boxen';
import path from 'node:path';
import fs from 'node:fs';
const fsp = fs.promises;

(async () => {
  const paths = await globby('tests/*');
  try {
    await execaCommand('g++ -std=gnu++17 t.cpp');
  } catch (e) {
    console.log(chalk.red(`${logSymbols.error} Compile Failed!`));
    console.log(e.stderr);
    process.exit(1);
  }

  if (!paths.length) {
    console.error(`${logSymbols.error} There are no test cases`);
    process.exit(1);
  }

  let idx = 1;
  const result = [];
  for (const testFilePath of paths) {
    const filename = path.parse(testFilePath).base;
    const content = await fsp.readFile(testFilePath, { encoding: 'utf-8' });
    await fsp.writeFile('input', content, { encoding: 'utf-8' });

    console.log(chalk.white(`-------------- Test case ${idx} --------------`));
    let stdout, stderr;

    try {
      const res = await execaCommand('./a.out');
      stdout = res.stdout;
      stderr = res.stderr;
    } catch {}

    if (stderr) {
      console.log(chalk.gray(`${logSymbols.info} [DEBUG]: `, stderr));
    }

    const answerPath = path.resolve(`answers/${filename}`);
    if (await pathExists(answerPath)) {
      const expected = await fsp.readFile(answerPath, { encoding: 'utf-8' });
      if (stdout === expected) {
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

  if (result.length) {
    console.log(boxen(result.join('\n'), { padding: 1 }));
  }
}) ();

