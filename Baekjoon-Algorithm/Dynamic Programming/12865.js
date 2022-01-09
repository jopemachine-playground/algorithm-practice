const fs = require('fs');
const [first, ...lines] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
// const [first, ...lines] = `
// 4 7
// 6 13
// 4 8
// 3 6
// 5 12
// `.trim().split('\n');

const [N, K] = first.split(' ');
const items = lines.map(line => line.split(' ').map(e => +e)).map((item) => {
  return {
    weight: item[0],
    value: item[1],
  };
});

const dp = [];
for (let i = 0; i < 100; ++i) {
  dp[i] = [];
}

const go = (start = -1, remaining = K) => {
  let ret = 0;
  if (start !== -1 && dp[start][remaining]) {
    return dp[start][remaining];
  }

  for (let i = start + 1; i < N; ++i) {
    ret = Math.max(
      ret,
      remaining >= items[i].weight ? (items[i].value + go (i, remaining - items[i].weight)) : 0,
    );
  }

  if (start !== -1) dp[start][remaining] = ret;

  return ret;
};

console.log(go());