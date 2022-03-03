import fs from 'node:fs';
const fsp = fs.promises;

(async () => {
  await fsp.rmdir('tests', { force: true });
  await fsp.rmdir('answers', { force: true });
  await fsp.mkdir('tests');
  await fsp.mkdir('answers');
}) ();