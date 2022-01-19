const fs = require('fs');
const [first, ...inputs] = fs.readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split('\n');
// const [first, ...inputs] = `
// 3 3
// D.*
// ...
// .S.
// `
//   .trim()
//   .split('\n');
const map = inputs.map(input => input.split(''));

const [R, C] = first.split(' ').map(e => +e);

let start;
const waterStart = [];

const deltas = [
  { r: 1, c: 0 },
  { r: 0, c: 1 },
  { r: 0, c: -1 },
  { r: -1, c: 0 },
];

const [PLAYER_ENUM, WATER_ENUM] = [0, 1];

const findStartEnd = () => {
  for (let i = 0; i < R; ++i) {
    for (let j = 0; j < C; ++j) {
      // dist는 도착칸에서만 쓰이기 때문에 도착칸을 미리 세어둔다.
      if (map[i][j] === 'S') start = { r: i, c: j, dist: 1, type: PLAYER_ENUM };
      else if (map[i][j] === '*') waterStart.push({ r: i, c: j, type: WATER_ENUM });
    }
  }
};

findStartEnd();

// 해당 칸이 물과 인접해 있거나 물임.
const isNextToWater = (i, j) => {
  if (map[i][j] === '*') return true;
  for (const delta of deltas) {
    const nr = i + delta.r;
    const nc = j + delta.c;
    if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
    if (map[nr][nc] === '*') return true;
  }
  return false;
};

const visited = Array.from(Array(R), () => Array(C));
const waterVisited = Array.from(Array(R), () => Array(C));

// 디버깅 용
const print = (r, c, dist) => {
  console.log('time: ', dist - 1);

  for (let i = 0; i < R; ++i) {
    for (let j = 0; j < C; ++j) {
      if (i === r && c === j) process.stdout.write('p');
      else process.stdout.write(map[i][j]);
    }
    console.log();
  }
  console.log('-------------------------------');
};

const go = () => {
  // 물이 먼저 움직이고 고슴도치가 움직인다.
  const que = [...waterStart, start];

  while (que.length > 0) {
    const { r, c, type, dist } = que.shift();
    if (type === PLAYER_ENUM) {

      // print(r, c, dist);

      for (const delta of deltas) {
        const nr = r + delta.r;
        const nc = c + delta.c;
        if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;

        // 도착
        if (map[nr][nc] === 'D') return dist;

        // 이미 방문한 칸 패스
        if (visited[nr][nc]) continue;

        // 칸이 벽이거나 물인 경우, 물에 인접한 경우 패스
        if (map[nr][nc] === 'X' || isNextToWater(nr, nc)) continue;

        visited[nr][nc] = true;

        que.push({
          r: nr,
          c: nc,
          type: PLAYER_ENUM,
          dist: dist + 1,
        });
      }
    } else {
      map[r][c] = '*';

      for (const delta of deltas) {
        const nr = r + delta.r;
        const nc = c + delta.c;
        if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;

        // 방문한 적 있으면 패스
        if (waterVisited[nr][nc]) continue;
        waterVisited[nr][nc] = true;

        // 칸이 벽이거나 이미 물인 경우 패스, 도착 칸인 경우 패스
        if (
          map[nr][nc] === 'X' ||
          map[nr][nc] === 'D' ||
          map[nr][nc] === '*'
        ) continue;

        que.push({
          r: nr,
          c: nc,
          type: WATER_ENUM,
        });
      }
    }
  }

  return false;
};

const result = go();
console.log(result === false ? 'KAKTUS' : result);