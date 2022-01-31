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
  const nums = inputs.map(input => input.split(' ').map(e => +e));

  let x, y;
  // 위 두 점의 x좌표가 같다면
  if (nums[0][0] === nums[1][0]) {
    x = nums[2][0];
  }
  else if (nums[1][0] === nums[2][0]) {
    x = nums[0][0];
  }
  else {
    x = nums[1][0];
  }

  // 위 두 점의 y좌표가 같다면
  if (nums[0][1] === nums[1][1]) {
    y = nums[2][1];
  }
  else if (nums[1][1] === nums[2][1]) {
    y = nums[0][1];
  }
  else {
    y = nums[1][1];
  }

  console.log(`${x} ${y}`);
};

// solve();
