const fs = require('fs');
const [first, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [first, ...inputs] = `
// 4 11
// 802
// 743
// 457
// 539`.trim().split("\n");
const [N, K] = first.split(' ').map(e => +e);
const nums = inputs.map(e => +e);

const getMaxCount = (len) => {
  let result = 0;
  for (let i = 0; i < nums.length; ++i) {
    result += Math.floor(nums[i] / len);
  }
  return result;
};

let start = 0;
let end = Math.max(...nums);

let ans = -1;

while (start <= end) {
  let mid = Math.floor((start + end) / 2);
  const maxCount = getMaxCount(mid);

  // 주어진 길이로 랜선을 K개보다 많이 만들 수 있으면 더 길게 자를 수 있는지 봐야한다.
  if (K <= maxCount) {
    start = mid + 1;
    ans = mid;
  } else {
    end = mid - 1;
  }
}

console.log(ans);