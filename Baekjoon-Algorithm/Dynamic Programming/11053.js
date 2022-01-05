// Ref: 종만북
const fs = require('fs');
const [N, inputs] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
// const [N, inputs] = `
// 5
// 40 1 5 10 90
// `.trim().split('\n');

const nums = inputs.split(' ').map(str => Number(str));

const cache = [];

const solve = (start = 0) => {
  if (cache[start] !== undefined) {
    return cache[start];
  }

  let ret = 1;
  for (let i = start + 1; i < nums.length; ++i) {
    if (nums[start] < nums[i]) {

      ret = Math.max(ret, 1 + solve(i));
      cache[start] = ret;
    }
  }

  return ret;
}

let ans = 0;

for (let i = 0; i < nums.length; ++i) {
  ans = Math.max(ans, solve(i));
}

console.log(ans);
