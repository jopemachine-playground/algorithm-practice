import {execaCommand} from 'execa';
import {globby} from 'globby';
import chalk from 'chalk';
import logSymbols from 'log-symbols';
import fs from 'node:fs';
const fsp = fs.promises;

(async () => {
  const paths = await globby('tests/*');
  await execaCommand('g++ -std=gnu++17 t.cpp');

  if (!paths.length) {
    console.error(`${logSymbols.error} There are no test cases`);
    process.exit(1);
  }

  let idx = 1;
  for (const testFilePath of paths) {
    const content = await fsp.readFile(testFilePath, { encoding: 'utf-8' });
    await fsp.writeFile('input', content, { encoding: 'utf-8' });

    console.log(chalk.white(`-------------- Test case ${idx++} --------------`));
    const {stdout, stderr} = await execaCommand('./a.out');
    console.log(stdout);

    if (stderr) {
      console.log(chalk.gray(`${logSymbols.info} [DEBUG]: `, stderr));
    }
  }
}) ();

