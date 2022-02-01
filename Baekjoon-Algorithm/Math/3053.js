const readline = require('readline');
// const inputs = `
// 5 5
// 5 7
// 7 5`.trim().split('\n');

const inputs = [];

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

const solve = () => {
  const R = +inputs[0];
  console.log(Math.PI * R * R);
  console.log(R * R * 2);
};