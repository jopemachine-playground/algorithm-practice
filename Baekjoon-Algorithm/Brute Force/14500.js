const fs = require('fs');
const [first, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [first, ...inputs] = `
// 4 10
// 1 2 1 2 1 2 1 2 1 2
// 2 1 2 1 2 1 2 1 2 1
// 1 2 1 2 1 2 1 2 1 2
// 2 1 2 1 2 1 2 1 2 1
// `.trim().split("\n");

const [N, M] = first.split(' ').map(e => +e);
const map = inputs.map((input) => input.split(' ').map((e) => +e));

const visited = [];
for (let i = 0; i < N; ++i) {
  visited[i] = [];
  for (let j = 0; j < M; ++j) {
    visited[i][j] = false;
  }
}

const deltas = [
  { x: 1, y: 0},
  { x: -1, y: 0},
  { x: 0, y: 1},
  { x: 0, y: -1},
];

const go = (x, y, depth, sum) => {
  if (depth >= 4) {
    return sum;
  }

  visited[x][y] = true;

  let maxValue = sum;
  for (const delta of deltas) {
    const nx = x + delta.x;
    const ny = y + delta.y;

    if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
      if (visited[nx][ny]) continue;
      maxValue = Math.max(maxValue, go(nx, ny, depth + 1, sum + map[nx][ny]));
    }
  }

  visited[x][y] = false;
  return maxValue;
};

let max = 0;

for (let i = 0; i < N; ++i) {
  for (let j = 0; j < M; ++j) {
    let ans = go (i, j, 1, map[i][j]);

    let b = [0, 0, 0, 0];
    let cases = [0, 0, 0, 0];

    // ㅜ
    if (i + 1 < N && j + 2 < M) {
      b[0] = map[i][j];
      b[1] = map[i][j + 1];
      b[2] = map[i][j + 2];
      b[3] = map[i + 1][j + 1];
      cases[0] = b.reduce((prev, curr) => prev + curr, 0);
    }
    
    // ㅏ
    if (i + 2 < N && j + 1 < M) {
      b[0] = map[i][j];
      b[1] = map[i + 1][j];
      b[2] = map[i + 1][j + 1];
      b[3] = map[i + 2][j];
      cases[1] = b.reduce((prev, curr) => prev + curr, 0);
    }

    // ㅓ
    if (i + 2 < N && j - 1 >= 0) {
      b[0] = map[i][j];
      b[1] = map[i + 1][j];
      b[2] = map[i + 1][j - 1];
      b[3] = map[i + 2][j];
      cases[2] = b.reduce((prev, curr) => prev + curr, 0);
    }

    // ㅗ
    if (i + 1 < N && j - 1 >= 0 && j + 1 < M) {
      b[0] = map[i][j];
      b[1] = map[i + 1][j];
      b[2] = map[i + 1][j - 1];
      b[3] = map[i + 1][j + 1];
      cases[3] = b.reduce((prev, curr) => prev + curr, 0);
    }

    max = Math.max(Math.max(...cases), ans, max);
  }
}

console.log(max);