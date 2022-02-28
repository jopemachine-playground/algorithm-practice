import { globby } from 'globby';
import fs from 'node:fs';
import process from 'node:process';
import logSymbols from 'log-symbols';
const fsp = fs.promises;

import './clean.js';

const problemNumber = process.argv[2];

(async () => {
  const paths = await globby(`**/${problemNumber}*.*`);

  if (paths.length === 0) {
    console.error(`Failed to find '${problemNumber}'`);
    process.exit(1);
  }

  if (paths.length > 1) {
    console.error('Failed to set problem.');
  } else {
    console.log(`${logSymbols.success} Set problem path successfully: '${paths[0]}'`);
    const execFileContent = await fsp.readFile('t.cpp', { encoding: 'utf-8' });
    const [_, ...content] = execFileContent.split('\n');

    await fsp.writeFile('t.cpp', [
      `#include "${paths[0]}"`,
      ...content
    ].join('\n'), { encoding: 'utf-8' });
  }
})();
