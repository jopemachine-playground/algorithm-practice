const fs = require('fs');
const [n, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
// const [n, ...inputs] = `
// 10
// 1 1
// 1 2
// 1 3
// 1 4
// 1 5
// 1 6
// 1 7
// 1 8
// 1 9
// 1 10
// `.trim().split('\n');

const N = Number(n);

const times = [];
const profits = [];
for (const input of inputs) {
  const [T, P] = input.split(' ').map(str => Number(str));
  times.push(T);
  profits.push(P);
}

const cache = [];

for (let i = 0; i < N; i++) {
  cache[i] = false;
}

const go = (idx = 0) => {
  // 배열 다 돌음
  if (idx === N) return 0;
  if (idx > N) return Number.MIN_SAFE_INTEGER;
  if (cache[idx]) return cache[idx];

  const sum = Math.max(
    go (idx + 1),
    go (idx + times[idx]) + profits[idx],
  );

  cache[idx] = sum;

  return sum;
};

console.log(go ());