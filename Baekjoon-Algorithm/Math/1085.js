const readline = require('readline');
// const inputs = ['161 181 762 375'];
const inputs = [];

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

const solve = () => {
  const [x, y, w, h] = inputs[0].split(' ').map(e => +e);
  console.log(Math.min(x, w-x, y, h-y));
};

// solve();
