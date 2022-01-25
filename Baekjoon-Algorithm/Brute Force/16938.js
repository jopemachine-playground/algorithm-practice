const fs = require('fs');
// const [first, second] = 
// `3 1 3 0
// 1 2 3`.trim().split('\n');
const [first, second] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
const [N, L, R, X] = first.split(' ').map(e => +e);
const nums = second.split(' ').map(e => +e);

let result = 0;
nums.sort((a, b) => a - b);

const go = (picked = [], idx = 0) => {
  const max = picked.length === 0 ? -1 : picked[picked.length - 1];
  const min = picked.length === 0 ? -1 : picked[0];

  const sum = picked.reduce((result, curr) => result + curr, 0);

  if (idx === nums.length) {
    if (picked.length >= 2) {
      if (max - min >= X && sum <= R && sum >= L) {
        ++result;
      }
    }

    return;
  }

  // To do:: 여기서 가지치기 해서 백트랙킹 할 수 있을 거 같은데?

  // 고르고 진행
  picked.push(nums[idx]);
  go (picked, idx + 1);
  picked.pop();

  // 안 고르고 진행
  go (picked, idx + 1);
};

go();

console.log(result);