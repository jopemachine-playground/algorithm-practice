const fs = require('fs');
const [first, inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [first, inputs] = `8 3
// 1 5 4 6 2 1 3 7`.trim().split("\n");

const [N, M] = first.split(' ').map(e => +e);
const nums = inputs.split(' ').map(e => +e);

let min = Infinity, max = -Infinity;
for (let i = 0; i < nums.length; ++i) {
  min = Math.min(min, nums[i]);
  max = Math.max(max, nums[i]);
}

// 구간점수의 최댓값이 mid 이하인 M개의 구간을 만들 수 있는가? 
const possible = (mid) => {
  // 마지막 구간의 갯수 1을 더해준다.
  let intervalCnt = 1;

  let min = nums[0];
  let max = nums[0];

  for (let i = 1; i < nums.length; ++i) {
    // 새 수가 구간보다 작은 값인 경우..
    if (nums[i] < min) {
      min = nums[i];
      const diff = max - min;
      // diff가 mid 보다 크면 다음 수를 이 구간에 포함시킬 수 없음. 즉, 새 구간을 만든다.
      // 실제로 새 구간을 만들 필요는 없고 min, max 두 포인터를 nums[i]로 초기화 시켜주면 된다.
      if (diff > mid) {
        ++intervalCnt;
        max = nums[i];
      }
    }
    // 새 수가 구간보다 큰 값인 경우..
    else if (nums[i] > max) {
      max = nums[i];
      const diff = max - min;
      // diff가 mid 보다 크면 다음 수를 이 구간에 포함시킬 수 없음. 즉, 새 구간을 만든다.
      // 실제로 새 구간을 만들 필요는 없고 min, max 두 포인터를 nums[i]로 초기화 시켜주면 된다.
      if (diff > mid) {
        ++intervalCnt;
        min = nums[i];
      }
    }
  }

  return intervalCnt <= M;
};

let ans = -1;

// 구간 점수의 최댓값을 이분 탐색으로 짐작해 나감,
let left = 0;
let right = max - min;

while (left <= right) {
  let mid = Math.floor((left + right) / 2);

  // 가능하다면 더 작은 값으로 시도해 본다.
  if (possible(mid)) {
    right = mid - 1;
    ans = mid;
  } else {
    left = mid + 1;
  }
}

console.log(ans);