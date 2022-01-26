const fs = require('fs');
const [first, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [first, ...inputs] = `
// 5 3
// 1 2
// 3 4
// 1 3
// `.trim().split("\n");

const [N, M] = first.split(' ').map(e => +e);

const banArr = M === 0 ? [] : inputs.map(input => input.split(' ').map(e => +e));
const bans = Array.from(Array(N + 1), () => Array(N + 1).fill(false));

for (let i = 0; i < banArr.length; ++i) {
  const [r, c] = banArr[i];
  bans[r][c] = bans[c][r] = true;
}

let res = 0;
for (let i = 1; i <= N; ++i) {
  for (let j = i + 1; j <= N; ++j) {
    // i, j 아이스크림을 함께 고를 수 없는 경우 일찍 종료.
    if (bans[i][j]) continue;
    
    for (let k = j + 1; k <= N; ++k) {
      // (i, k), (j, k) 아이스크림을 함께 고를 수 없는 경우 종료.
      if (bans[i][k] || bans[j][k]) continue;
      ++res;
    }
  }
}

console.log(res);