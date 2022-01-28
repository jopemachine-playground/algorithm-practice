const inputs = [];
const readline = require('readline');

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

const solve = () => {
  console.log(+inputs[0] - 543);
};