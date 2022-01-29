const readline = require('readline');
const inputs = [];
// const inputs = `53`.trim().split('\n');

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

const solve = () => {
  let N = +inputs[0];

  let cnt = 1;
  let k = 1;
  let i = 6;

  for (; k < N; i += 6) {
    k += i;
    ++cnt;
  }

  console.log(cnt);
};