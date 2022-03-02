import fs from 'node:fs';
const fsp = fs.promises;

(async () => {
  await fsp.rmdir('tests', { recursive: true ,force: true });
  await fsp.rmdir('answers', { recursive: true ,force: true });
  await fsp.mkdir('tests');
  await fsp.mkdir('answers');
}) ();