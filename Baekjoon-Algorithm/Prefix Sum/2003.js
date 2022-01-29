const fs = require('fs');
// const [first, second] = `10 5
// 1 2 3 4 2 5 3 1 1 2`.trim().split("\n");
const [first, second] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [N, M] = first.split(' ').map(e => +e);
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

let cnt = 0;

// 구간 합이 M보다 작은 경우 right를 증가시켜 구간 합을 크게 만든다.
// M보다 큰 경우 left를 증가시켜 구간 합을 작게 만든다.
// 같은 경우 right를 증가시킨다. 
while (right < N) {
  const sum = getPrefixSum(left, right);

  if (sum === M) {
    ++cnt;
    ++right;
  } else if (sum > M) {
    ++left;
  } else {
    ++right;
  }
}

console.log(cnt);