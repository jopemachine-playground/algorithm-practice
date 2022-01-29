const fs                = require('fs');
// const [first, ...inputs]    = `
// 8 6
// 0 0 1 2 2 2
// 0 0 1 2 2 2
// 0 1 1 0 2 2
// 1 2 2 0 1 1
// 1 2 2 1 0 0
// 1 2 1 0 2 0
// 1 1 0 0 0 1
// 0 1 0 0 0 0`.trim().split('\n');
const [first, ...inputs]    = fs.readFileSync("/dev/stdin").toString().trim().split('\n');

const [N, M] = first.split(' ').map(e => +e);
const map = inputs.map(input => input.split(' ').map(e => +e));

const findAllEnemys = () => {
  let res = [];
  for (let i = 0; i < N; ++i) {
    for (let j = 0; j < M; ++j) {
      if (map[i][j] === 2) {
        res.push({ r: i, c: j });
      }
    }
  }
  return res;
};

const enemys = findAllEnemys();

const deltas = [
  { r: 1, c: 0 },
  { r: 0, c: 1 },
  { r: 0, c: -1 },
  { r: -1, c: 0 },
];

const printMap = () => {
  console.log('----------------------------------------');
  console.log(map.map(line => line.join(' ')).join('\n'));
}

const checkRange = (r, c) => {
  return r >= 0 && c >= 0 && r < N && c < M;
}

let visited = Array.from(Array(N), () => Array(M).fill(false));

const dfs = (r, c) => {
  // 아래 4줄로 깔끔하게 예외 처리해 줄 수 있다는 점.
  if (!checkRange(r, c)) return 0;
  if (visited[r][c]) return 0;
  if (map[r][c] === 1) return 0;
  if (map[r][c] === 0) return Infinity;

  visited[r][c] = true;
  let ret = 1;

  for (const delta of deltas) {
    const nr = r + delta.r;
    const nc = c + delta.c;
    ret += dfs(nr, nc);
  }

  return ret;
}

let max = -Infinity;

// 모든 2에서 시작해서 1로 둘러 쌓여 있는 바둑알 갯수 셈
const findKillCnt = () => {
  visited = Array.from(Array(N), () => Array(M).fill(false));

  let killCnt = 0;
  for (const enemy of enemys) {
    const { r, c } = enemy;
    if (!visited[r][c]) {
      let cnt = dfs(r, c);
      if (cnt < Infinity) killCnt += cnt;
    }
  }

  return killCnt;
};

const go = (depth = 0) => {
  if (depth === 2) {
    max = Math.max(max, findKillCnt());
    return;
  }

  for (let i = 0; i < N; ++i) {
    for (let j = 0; j < M; ++j) {
      if (map[i][j] === 0) {
        map[i][j] = 1;
        // printMap();
        go(depth + 1);
        map[i][j] = 0;
      }
    }
  }
};

go ();

console.log(max);