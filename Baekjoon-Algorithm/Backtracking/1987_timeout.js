const fs                = require('fs');
const [first, ...map]   = fs.readFileSync("/dev/stdin")
                          .toString()
                          .trim()
                          .split('\n');

// let [first, ...map]   = 
// `5 5
// IEFCJ
// FHFKC
// FFALF
// HFGCF
// HMCHH`.trim().split('\n');

const [R, C]            = first.split(' ');

const deltas = [
  // 오른쪽
  [0, 1],
  // 왼쪽
  [0, -1],
  // 아래 쪽
  [1, 0],
  // 위 쪽
  [-1, 0],
];

let answer = 0;
const paths = {};

const go = (x = 0, y = 0, depth = 0) => {
  if (x >= R || y >= C || x < 0 || y < 0) return;

  if (paths[map[x][y]]) {
    answer = Math.max(answer, depth);
    return;
  }

  for (const delta of deltas) {
    const nx = x + delta[1];
    const ny = y + delta[0];

    if (nx >= R || nx < 0 || ny >= C || ny < 0) continue;

    paths[map[x][y]] = true;
    go(nx, ny, depth + 1);
    paths[map[x][y]] = false;
  }
};

go();

console.log(answer);