const fs = require('fs');
const [first, inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [first, inputs] = `
// 4 7
// 20 15 10 17`.trim().split("\n");

const [N, M] = first.split(' ').map(e => +e);
const nums = inputs.split(' ').map(e => +e);

const getTarget = (cutValue) =>
  nums.reduce((result, height) =>
    result + ((height > cutValue) ? height - cutValue : 0)
  , 0);

let ans = -1;
let start = 0;
let end = nums[0];

// nums 길이 최댓값이 1백만이기 때문에 Math.max(...nums) 하면 스택이 터짐에 주의..
for (const k of nums) {
  if (k > end) end = k; 
}

while (start <= end) {
  const mid = Math.floor((start + end) / 2);
  const target = getTarget(mid);

  if (target >= M) {
    ans = mid;
    start = mid + 1;
  } else {
    end = mid - 1;
  }
}

console.log(ans);