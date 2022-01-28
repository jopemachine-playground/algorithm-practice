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
  const [x, y] = inputs;
  
  if (x > 0 && y > 0) {
    console.log(1);
  }
  if (x > 0 && y < 0) {
    console.log(4);
  }
  if (x < 0 && y < 0) {
    console.log(3);
  }
  if (x < 0 && y > 0) {
    console.log(2);
  }
};