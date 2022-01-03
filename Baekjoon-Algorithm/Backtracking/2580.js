// Ref: 백준 알고리즘 중급 강좌

const fs    = require('fs');
const map = fs.readFileSync("/dev/stdin")
                .toString()
                .trim()
                .split('\n')
                .map((str) => str.split(' ').map(str => Number(str)));
// const map = `
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// `.trim().split('\n').map((str) => str.split(' ').map(str => Number(str)));

const c1 = [];
const c2 = [];
const c3 = [];

const getAreaIdx = (x, y) => {
  return 3 * Math.floor(y / 3) + Math.floor(x / 3)
};

for (let i = 0; i < 9; ++i) {
  c1[i] = [];
  c2[i] = [];
  c3[i] = [];
}

for (let i = 0; i < 9; ++i) {
  for (let j = 0; j < 9; ++j) {
    if (map[i][j] !== 0) {
      c1[i][map[i][j]] = true;
      c2[j][map[i][j]] = true;
      c3[getAreaIdx(i, j)][map[i][j]] = true; 
    }
  }
}

const go = (z) => {
  if (z === 81) {
    console.log(map.map((str) => str.join(' ')).join('\n'));
    process.exit(0);
  }

  let x = Math.floor(z / 9);
  let y = z % 9;

  if (map[x][y] !== 0) {
    go(z + 1);
    return;
  }

  for (let i = 1; i <= 9; ++i) {
    if (!c1[x][i] && !c2[y][i] && !c3[getAreaIdx(x, y)][i]) {
      [c1[x][i], c2[y][i], c3[getAreaIdx(x, y)][i]] = [true, true, true];
      map[x][y] = i;
      go(z + 1);
      map[x][y] = 0;
      [c1[x][i], c2[y][i], c3[getAreaIdx(x, y)][i]] = [false, false, false];
    }
  }
}

go(0);

