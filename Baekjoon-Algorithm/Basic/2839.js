// const inputs = ['8'];
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
  const N = +inputs[0];

  let res = Infinity;
  // 넣을 5kg 봉지의 갯수 -> i
  for (let i = 0; i <= Math.floor(N / 5); ++i) {
    // 넣을 3kg 봉지의 갯수 -> j
    for (let j = 0; j <= Math.floor(N / 3); ++j) {
      if (3 * j + 5 * i === N) {
        res = Math.min(res, i + j);
      }
    }
  }

  console.log(res === Infinity ? -1 : res);
};

// solve();