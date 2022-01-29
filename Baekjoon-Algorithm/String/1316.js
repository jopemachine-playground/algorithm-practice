const readline = require('readline');
const inputs = [];
// const inputs = `
// 1
// z`.trim().split('\n');

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

const solve = () => {
  const N = +inputs[0];
  let cnt = 0;

  for (let i = 1; i < inputs.length; ++i) {
    const dict = {};
    const str = inputs[i];
    let charBuf = '';
    let isGroupWord = true;
    for (const ch of str) {
      if (!dict[ch]) {
        dict[ch] = true;
      }
      else if (dict[ch] === true && charBuf !== ch) {
        isGroupWord = false;
        break;
      }

      charBuf = ch;
    }
    if (isGroupWord) cnt++;
  }

  console.log(cnt);
};
