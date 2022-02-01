const readline = require('readline');
// const inputs = ``;
const inputs = [];

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

const solve = () => {
  const N = +inputs[0];
  let find = false;

  for (let i = 1; i < N; ++i) {
    const str = String(i);
    let sum = 0;
    for (const ch of str) {
      sum += (+ch);
    }
    sum += i;

    if (sum === N) {
      find = true;
      console.log(i);
      break;
    }
  }

  if (!find) {
    console.log(0);
  }
};

// solve();