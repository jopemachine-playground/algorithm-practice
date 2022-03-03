import fs from 'node:fs';
const fsp = fs.promises;

(async () => {
  await fsp.rm('tests', { recursive: true ,force: true });
  await fsp.rm('answers', { recursive: true ,force: true });
  await fsp.mkdir('tests');
  await fsp.mkdir('answers');
}) ();