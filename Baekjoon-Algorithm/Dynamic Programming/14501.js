const fs = require('fs');
// const [N, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
const [N, ...inputs] = `
10
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
`.trim().split('\n');

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

const go = (idx = 0, sum = 0) => {
  // 배열 다 돌음
  if (idx >= times.length) {
    return sum;
  }

  if (cache[idx]) {
    return sum + cache[idx];
  }

  // 일할 수 있는 기간보다 많은 양을 요구하면 다음으로 넘김
  if (idx + times[idx] > N) {
    sum = go (idx + 1, sum);
  }
  // 일할 수 있으면 일을 하는 경우, 하지 않는 경우를 나눠 최댓값을 계산함.
  else {
    sum = Math.max(go (idx + 1, sum), go (idx + times[idx], sum + profits[idx]));
    cache[idx] = sum;
  }

  return sum;
};

console.log(go ());