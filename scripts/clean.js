import fs from 'node:fs';
const fsp = fs.promises;

(async () => {
  await fsp.rmdir('tests', { recursive: true ,force: true });
  await fsp.mkdir('tests');
}) ();