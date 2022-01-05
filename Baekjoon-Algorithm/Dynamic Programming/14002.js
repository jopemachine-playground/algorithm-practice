// Ref: 종만북
const fs = require('fs');
const [N, inputs] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
// const [N, inputs] = `
// 6
// 1 5 6 2 3 4
// `.trim().split('\n');

const nums = inputs.split(' ').map(str => Number(str));
// 반복문 제거 위해 가상의 숫자를 하나 추가 (나중에 빼 줘야 됨)
nums[-1] = -1;

const cache  = [];

const solve = (idx = -1) => {
  if (cache[idx]) {
    return cache[idx];
  }

  let ret = 1;
  for (let i = idx + 1; i < nums.length; ++i) {
    if (nums[i] > nums[idx]) {
      const tmp = solve(i);
      if (ret < 1 + tmp) {
        ret = Math.max(ret, 1 + tmp);
      }
    }
  }

  cache[idx] = ret;
  return ret;
};

// 가상의 값 빼기
const len = solve() - 1;

// cache[i]는 i에서 시작하는 부분 수열 중 nums[i] 보다 큰 수만을 포함하는 수열의 갯수이므로
// 맨 앞에서 부터 하나 씩 해당 수열을 만들어나가면 path가 나온다.
let pointer = cache[cache.findIndex((val) => val === len)];
const path = [];

for (let i = 0; i < nums.length && pointer > 0; ++i) {
  if (cache[i] === pointer) {
    --pointer;
    path.push(nums[i]);
  }
}

console.log(len);
console.log(path.join(' '));