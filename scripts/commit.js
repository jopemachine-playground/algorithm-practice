import {execa, execaCommand} from 'execa';
import logSymbols from 'log-symbols';
import { globby } from 'globby';
import path from 'node:path';

const problemNumber = process.argv[2];

(async () => {
  const paths = await globby(`**/${problemNumber}*.*`);

  if (paths.length === 0) {
    console.error(`${logSymbols.error} Failed to find '${problemNumber}'`);
    process.exit(1);
  }

  if (paths.length > 1) {
    console.error('Failed to set problem.');
  } else {
    const { dir } = path.parse(paths[0]);
    await execaCommand(`git add ${paths[0]}`);
    // console.log(`git commit -m "\[${dir}\] Solve ${problemNumber}"`);
    await execa('git', ['commit', '-m', `[${dir}] Solve ${problemNumber}`]);
    await execaCommand(`git push origin master`);
    console.log(`${logSymbols.success} Commit and push problem successfully: '${paths[0]}'`);
  }

}) ();