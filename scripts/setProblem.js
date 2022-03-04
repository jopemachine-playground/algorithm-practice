import {globby} from 'globby';
import logSymbols from 'log-symbols';
import chalk from 'chalk';
import inquirer from 'inquirer';
import process from 'node:process';
import fs from 'node:fs';
const fsp = fs.promises;

import './clean.js';

const problemNumber = process.argv[2];

(async () => {
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
          choices: paths.map((path) => {
            return { name: path, value: path };
          })
        }
      ])
      .then(selection => {
        paths = [selection.file];
      });
  }

  console.log(`${logSymbols.success} Set problem path successfully: '${paths[0]}'`);
  const execFileContent = await fsp.readFile('t.cpp', { encoding: 'utf-8' });
  const [_, ...content] = execFileContent.split('\n');

  await fsp.writeFile('t.cpp', [
    `#include "${paths[0]}"`,
    ...content
  ].join('\n'), { encoding: 'utf-8' });
})();
