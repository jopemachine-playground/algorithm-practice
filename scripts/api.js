import fs from 'node:fs';
import {unusedFilename} from 'unused-filename';
import chalk from 'chalk';
import open from 'open';
const fsp = fs.promises;

const addTest = async (copiedTexts) => {
  console.log(chalk.gray(`Added test:\n\n`) + chalk.white(`${copiedTexts}\n`));
  await fsp.writeFile(await unusedFilename('tests/input'), copiedTexts, {
    encoding: 'utf-8',
  });
}

const addAnswer = async (copiedTexts) => {
  console.log(chalk.gray(`Added answer:\n\n`) + chalk.white(`${copiedTexts}\n`));
  await fsp.writeFile(await unusedFilename('answers/input'), copiedTexts, {
    encoding: 'utf-8',
  });
}

const clearTests = async () => {
  await fsp.rm('tests', { recursive: true ,force: true });
  await fsp.rm('answers', { recursive: true ,force: true });
  await fsp.mkdir('tests');
  await fsp.mkdir('answers');
};

const openProblem = async (problemNumber) => {
  open(`https://www.acmicpc.net/problem/${problemNumber}`, { wait: false });
}

export {
  addTest,
  addAnswer,
  clearTests,
  openProblem,
}