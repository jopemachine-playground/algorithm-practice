import clipboard from 'clipboardy';
import fs from 'node:fs';
import {unusedFilename} from 'unused-filename';
const fsp = fs.promises;

(async () => {
  const copiedTexts = clipboard.readSync();
  await fsp.writeFile(await unusedFilename('tests/input'), copiedTexts, {
    encoding: 'utf-8',
  });
}) ();