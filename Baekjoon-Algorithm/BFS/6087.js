// Ref: 백준 알고리즘 강좌 중급
const fs = require('fs');
const [first, ...map] = fs.readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split('\n');
// const [first, ...map]    = `
// 7 8
// .......
// ......C
// ......*
// *****.*
// ....*..
// ....*..
// .C..*..
// .......
// `.trim().split('\n');

const [W, H] = first.split(' ').map(e => +e);

const deltas = [
  { r: 0, c: 1 },
  { r: 1, c: 0 },
  { r: -1, c: 0 },
  { r: 0, c: -1 },
];

const findStart = () => {
  for (let i = 0; i < H; ++i) {
    for (let j = 0; j < W; ++j) {
      if (map[i][j] === 'C') {
        return {
          r: i,
          c: j
        };
      }
    }
  }

  throw new Error('Start point not exist!');
};

// const trailMap = [];
const visited = [];

for (let i = 0; i < H; ++i) {
  visited[i] = [];
  // trailMap[i] = [];
  for (let j = 0; j < W; ++j) {
    // trailMap[i][j] = '.';
    visited[i][j] = [];
    for (let k = 0; k < deltas.length; ++k) {
      visited[i][j][k] = false;
    }
  }
}

const debug = () => {
  for (let i = 0; i < H; ++i) {
    for (let j = 0; j < W; ++j) {
      process.stdout.write(trailMap[i][j] + ' ');
    }
    console.log();
  }
}

const go = () => {
  const que = [];

  const { r: sr, c: sc } = findStart();

  que.push({
    r: sr,
    c: sc,
    mirrorCnt: -1,
  });

  while (que.length > 0) {
    const { r, c, mirrorCnt, } = que.shift();

    if (map[r][c] === 'C') {
      // C인데 시작점이 아니라면 도착.
      if (sr !== r || sc !== c) {
        return {
          r, c, mirrorCnt
        };
      }
    }

    for (let deltaIdx = 0; deltaIdx < deltas.length; ++deltaIdx) {
      const delta = deltas[deltaIdx];

      let idx = 0;
      // 해당 방향으로 벽에 부딪칠 떄 까지 나아가며 푸시.
      while (true) {
        const nr = r + delta.r * idx;
        const nc = c + delta.c * idx;
        // 범위 초과
        if (nr >= H || nc >= W || nr < 0 || nc < 0) break;
        // 벽에 부딪침
        if (map[nr][nc] === '*') break;
        // 같은 칸을 같은 방향으로 움직인 적이 있다면 방문한 적이 있음.
        if (visited[nr][nc][deltaIdx]) break;
        visited[nr][nc][deltaIdx] = true;

        que.push({
          r: nr,
          c: nc,
          mirrorCnt: mirrorCnt + 1,
        });

        idx++;
      }
    }
  }
};

const { mirrorCnt } = go() ?? { mirrorCnt: -1 };
console.log(mirrorCnt);