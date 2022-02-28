import {execaCommand} from 'execa';
import {globby} from 'globby';
import fs from 'node:fs';
import logSymbols from 'log-symbols';
const fsp = fs.promises;

(async () => {
  const paths = await globby('tests/*');
  await execaCommand('g++ -std=gnu++17 t.cpp');

  let idx = 1;
  for (const testFilePath of paths) {
    const content = await fsp.readFile(testFilePath, { encoding: 'utf-8' });
    await fsp.writeFile('input', content, { encoding: 'utf-8' });

    console.log(`-------------- Test case ${idx++} --------------`);
    const {stdout, stderr} = await execaCommand('./a.out');
    console.log(stdout);

    if (stderr) {
      console.log(`${logSymbols.info} DEBUG: `, stderr);
    }
  }
}) ();

