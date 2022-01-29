const fs = require('fs');
// const [first, second] = `10 15
// 5 1 3 5 16 7 4 9 2 8`.trim().split("\n");
const [first, second] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [N, S] = first.split(' ').map(e => +e);
const nums = second.split(' ').map(e => +e);

const getPartialSums = (nums) => {
  let res = [nums[0]];
  for (let i = 1; i < N; ++i) {
    res[i] = res[i - 1] + nums[i];
  }
  return res;
}

const partialSums = getPartialSums(nums);

const getPrefixSum = (i, j) => {
  return i > 0 ? partialSums[j] - partialSums[i - 1] : partialSums[j];
};

let left = 0;
let right = 0;
let result = Infinity;

while (right < N) {
  const sum = getPrefixSum(left, right);
  // 합이 S 이상인 경우 left를 증가시켜 구간합을 줄이자
  if (sum >= S) {
    result = Math.min(result, right - left + 1);
    ++left;
  } else {
    ++right;
  }
}

console.log(result === Infinity ? 0 : result);