const fs = require('fs');
const inputs = fs.readFileSync("/dev/stdin")
                .toString()
                .trim()
                .split('\n');
// const inputs = `
// 10
// 6 B2 1 B3
// 2 C4 9 C3
// 6 D3 8 E3
// 7 E1 4 F1
// 8 B7 4 B8
// 3 F5 2 F6
// 7 F7 6 F8
// 5 G4 9 G5
// 7 I8 8 I9
// 7 C9 2 B9
// C5 A3 D9 I4 A9 E5 A2 C6 I1
// 11
// 5 I9 2 H9
// 6 A5 7 A6
// 4 B8 6 C8
// 3 B5 8 B4
// 3 C3 2 D3
// 9 D2 8 E2
// 3 G2 5 H2
// 1 A2 8 A1
// 1 H8 3 I8
// 8 I3 7 I4
// 4 I6 9 I7
// I5 E6 D1 F2 B3 G9 H7 C9 E5
// 0
// `.trim().split('\n');

let map = [];
let rows = [];
let cols = [];
let areas = [];
let blocks = [];

const deltas = [
  { r: 0, c: 1 },
  { r: 1, c: 0 },
];

const alphabetDict = {
  A: 1,
  B: 2,
  C: 3,
  D: 4,
  E: 5,
  F: 6,
  G: 7,
  H: 8,
  I: 9
};

const convertPos = (pos) => {
  return {
    r: Number(alphabetDict[pos[0]]) - 1,
    c: Number(pos[1]) - 1,
  };
};

const getAreaIdx = (row, col) => {
  return 3 * Math.floor(row / 3) + Math.floor(col / 3);
};

const initialize = () => {
  map = Array.from(Array(9), () => Array(9).fill(0));
  rows = Array.from(Array(10), () => Array(10).fill(false));
  cols = Array.from(Array(10), () => Array(10).fill(false));
  areas = Array.from(Array(10), () => Array(10).fill(false));
  blocks = Array.from(Array(10), () => Array(10).fill(false));
};

const can = (r, c, num) => {
  return !rows[r][num] && !cols[c][num] && !areas[getAreaIdx(r, c)][num];
};

const check = (r, c, num, what) => {
  rows[r][num] = what;
  cols[c][num] = what;
  areas[getAreaIdx(r, c)][num] = what;
};

const printMap = (debug) => {
  if (debug) console.log('--------------------');
  // console.log(map.slice(0, 9).map(str => str.slice(0, 9).join('')).join('\n').trim());
  console.log(map.map(str => str.join('')).join('\n').trim());
};

const go = (z) => {
  if (z === 81) {
    console.log(`Puzzle ${puzzleIdx}`);
    printMap();
    return true;
  }

  const r = Math.floor(z / 9);
  const c = z % 9;

  // printMap(true);

  if (map[r][c] !== 0) {
    return go (z + 1);
  }

  for (const delta of deltas) {
    const nr = delta.r + r;
    const nc = delta.c + c;
    if (nr < 0 || nc < 0 || nr >= 9 || nc >= 9) continue;

    if (map[nr][nc] !== 0) continue;

    for (let i = 1; i <= 9; ++i) {
      for (let j = 1; j <= 9; ++j) {
        if (i === j) continue;
        if (blocks[i][j]) continue;

        if (
          can(r, c, i) &&
          can(nr, nc, j)
        ) {
          check(r, c, i, true);
          check(nr, nc, j, true);
          [
            blocks[i][j],
            blocks[j][i],
            map[r][c],
            map[nr][nc]
          ] = [
            true,
            true,
            i,
            j
          ];

          if (go (z + 1)) return true;

          [
            blocks[i][j],
            blocks[j][i],
            map[r][c],
            map[nr][nc]
          ] = [
            false,
            false,
            0,
            0
          ];

          check(r, c, i, false);
          check(nr, nc, j, false);
        }
      }
    }
  }

  return false;
};

let puzzleIdx = 1;
// 마지막 라인 제외
for (let i = 0; i < inputs.length - 1;) {
  initialize();

  const cnt = Number(inputs[i]);
  const lines = inputs.slice(i + 1, i + cnt + 1);
  const grids = inputs[i + cnt + 1].split(' ');

  for (const line of lines) {
    const [u, LU, v, LV] = line.split(' ');
    const U = +u;
    const V = +v;

    const { r: r1, c: c1 } = convertPos(LU);
    rows[r1][U] = true;
    cols[c1][U] = true;
    areas[getAreaIdx(r1, c1)][U] = true;
    map[r1][c1] = U;
    check(r1, c1, U, true);

    const { r: r2, c: c2 } = convertPos(LV);
    rows[r2][V] = true;
    cols[c2][V] = true;
    areas[getAreaIdx(r2, c2)][V] = true;
    map[r2][c2] = V;
    check(r2, c2, V, true);

    blocks[U][V] = true;
    blocks[V][U] = true;
  }

  let gridIdx = 1;
  for (const grid of grids) {
    const { r, c } = convertPos(grid);
    rows[r][gridIdx] = true;
    cols[c][gridIdx] = true;
    areas[getAreaIdx(r, c)][gridIdx] = true;
    map[r][c] = gridIdx;

    check(r, c, gridIdx, true);
    ++gridIdx;
  }

  go(0);

  ++puzzleIdx;
  map = undefined;
  i += (cnt + 1) + 1;
}