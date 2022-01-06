// Ref: 종만북
const fs = require('fs');
const [N, inputs] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
// const [N, inputs] = `
// 6
// 10 20 10 30 20 50
// `.trim().split('\n');

const nums = inputs.split(' ').map(str => Number(str));
// 반복문 제거 위해 가상의 숫자를 하나 추가 (나중에 빼 줘야 됨)
nums[-1] = -1;

const cache  = [];
const choices = [];

const solve = (idx = -1) => {
  if (cache[idx]) {
    return cache[idx];
  }

  let ret = 1;
  let bestIdx = -1;
  for (let i = idx + 1; i < nums.length; ++i) {
    if (nums[i] > nums[idx]) {
      const tmp = solve(i);
      if (ret < 1 + tmp) {
        ret = Math.max(ret, 1 + tmp);
        cache[idx] = ret;
        bestIdx = i;
      }
    }
  }

  choices[idx + 1] = bestIdx;

  return ret;
};

const reconstruct = (idx, seq = []) => {
  if (idx !== -1) seq.push(nums[idx]);
  let next = choices[idx + 1];
  if (next !== -1) reconstruct(next, seq);
  return seq;
};

// 가상의 값 빼기
const len = solve() - 1;

// console.log('choices: ', choices);

console.log(len);
console.log(reconstruct(-1).join(' '));