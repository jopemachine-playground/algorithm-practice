const readline = require('readline');
// const inputs = `
// 5
// 55 185
// 58 183
// 88 186
// 60 175
// 46 155
// `.trim().split('\n');
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
  const res = [];
  const nums = inputs.slice(1).map(input => input.split(' ').map(e => +e));

  for (let i = 0; i < N; ++i) {
    let idx = 1;
    for (let j = 0; j < N; ++j) {
      if (i === j) continue;
      if (nums[i][0] < nums[j][0] && nums[i][1] < nums[j][1]) ++idx;
    }
    res.push(idx);
  }
  console.log(res.join(' '));
};

// solve();