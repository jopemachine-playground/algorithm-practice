const fs = require('fs');
const inputs = fs.readFileSync("/dev/stdin").toString().trim().split("\n").map(input => input.split(' '));
// const inputs = `
// 1 1 1 1 1
// 1 1 1 1 1
// 1 1 1 1 1
// 1 1 1 2 1
// 1 1 1 1 1
// `.trim().split("\n").map(input => input.split(' '));

const deltas = [
  { r: 0, c: 1 },
  { r: 0, c: -1 },
  { r: 1, c: 0 },
  { r: -1, c: 0 },
];

const set = new Set();

const go = (r, c, res) => {
  if (res.length === 6) {
    set.add(res);
    return;
  }

  for (const delta of deltas) {
    const nr = r + delta.r;
    const nc = c + delta.c;

    if (nr >= 5 || nc >= 5 || nr < 0 || nc < 0) continue;

    go(nr, nc, res + inputs[nr][nc]);
  }
};

for (let i = 0; i < 5; ++i) {
  for (let j = 0; j < 5; ++j) {
    go (i, j, inputs[i][j]);
  }
}

console.log(set.size);