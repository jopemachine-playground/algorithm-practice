const fs = require('fs');
const [first, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
// const [first, ...inputs] = `
// 5
// 1
// 3
// 7
// 4
// 2`.trim().split('\n');

const N = +first;
const nums = inputs.map((val, idx) => {
  return {
    val: +val,
    idx,
  }
});

const sorted = [...nums].sort((a, b) => a.val - b.val);

let maxDiff = 0;
for (let i = 0; i < N; ++i) {
  maxDiff = Math.max(maxDiff, sorted[i].idx - nums[i].idx);
}

console.log(maxDiff + 1);