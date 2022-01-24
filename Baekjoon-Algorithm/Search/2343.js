const fs = require('fs');
const [first, inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [first, inputs] = `4 1
// 1 1 1 1`.trim().split("\n");

// N : 강의의 수, M : 블루레이의 갯수
const [N, M] = first.split(' ').map(e => +e);
const nums = inputs.split(' ').map(e => +e);

let max = -Infinity;
for (let i = 0; i < nums.length; ++i) {
  max = Math.max(max, nums[i]);
}

// 그리디 알고리즘.
// k는 만들려고 하는 블루레이의 최대 녹화 가능한 길이.
const possible = (k) => {
  let sumBuffer = 0;
  let i = 0;
  let remainingBluelayCount = M;

  if (max > k) return false;

  for (; i < nums.length; ++i) {
    if (remainingBluelayCount <= 0) break;

    // 이번 강의까지 딱 이 블루레이에 녹화하기
    if (sumBuffer + nums[i] === k) {
      sumBuffer = 0;
      --remainingBluelayCount;
    }
    // 이번 강의는 다음 블루레이에 녹화하기
    else if (sumBuffer + nums[i] > k) {
      sumBuffer = nums[i];
      // 이번 블루레이까지를 하나로 묶고, 다음 블루레이도 존재해야 true를 반환할 수 있다.
      --remainingBluelayCount;
      if (remainingBluelayCount < 1) break;
    }
    // 이번 강의를 이 블루레이에 녹화하기.
    else {
      sumBuffer += nums[i];
    }
  }

  // 반복문을 끝까지 돌았고, sumBuffer가 비어 있다면, k값을 최대로 하는 M개의 블루레이들에 모두 강의를 성공적으로 담음.
  if (i === nums.length) {
    return true;
  }

  return false;
};

let ans;
let left = 0;
// 강의의 수 * 강의의 길이의 worst case.
let right = 1000000000;

while (left <= right) {
  let mid = Math.floor((left + right) / 2);

  if (possible(mid)) {
    right = mid - 1;
    ans = mid;
  } else {
    left = mid + 1;
  }
}

console.log(ans);