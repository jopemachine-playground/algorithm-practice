const fs = require('fs');
const [N, k] = fs.readFileSync("/dev/stdin").toString().trim().split("\n").map(e => +e);
// const [N, k] = `
// 100000
// 1000000000
// `.trim().split("\n").map(e => +e);

const getCount = (mid) => {
  let sum = 0;
  for (let i = 1; i <= N; ++i) {
    sum += Math.min(Math.floor(mid / i), N);
  }
  return sum;
};

let ans = 0;
let left = 1;
let right = N * N;

while (left <= right) {
  let mid = Math.floor((left + right) / 2);
  
  const count = getCount(mid);
  
  if (count >= k) {
    ans = mid;
    right = mid - 1;
  } else {
    left = mid + 1;
  }
}

console.log(ans);