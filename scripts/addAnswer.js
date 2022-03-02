import clipboard from 'clipboardy';
import fs from 'node:fs';
import {unusedFilename} from 'unused-filename';
import chalk from 'chalk';
const fsp = fs.promises;

(async () => {
  const copiedTexts = clipboard.readSync();
  console.log(chalk.gray(`Added answer:\n\n`) + chalk.white(`${copiedTexts}\n`));
  await fsp.writeFile(await unusedFilename('answers/input'), copiedTexts, {
    encoding: 'utf-8',
  });
}) ();