const fs                = require('fs');
// const [first, ...map]   = `
// 5
// RRRBB
// GGBBB
// BBBRR
// BBRRR
// RRRRR`.trim().split('\n');

const [first, ...map]   = fs.readFileSync("/dev/stdin")
                            .toString()
                            .trim()
                            .split('\n');

const N = +first;

const deltas = [
  { r: 0, c: 1 },
  { r: 1, c: 0 },
  { r: 0, c: -1 },
  { r: -1, c: 0 },
];

const go = (ignoreRG) => {
  const que = [];
  const visited = [];

  for (let i = 0; i < N; ++i) {
    visited[i] = [];
    for (let j = 0; j < N; ++j) {
      visited[i][j] = false;
    }
  }

  let areaCnt = 0;

  for (let i = 0; i < N; ++i) {
    for (let j = 0; j < N; ++j) {
      if (visited[i][j]) continue;

      que.push({
        r: i,
        c: j,
      });

      while (que.length > 0) {
        const {r, c} = que.shift();
    
        for (const delta of deltas) {
          const nr = r + delta.r;
          const nc = c + delta.c;
          if (nr >= N || nc >= N || nr < 0 || nc < 0) continue;

          if (visited[nr][nc]) continue;
          // 구역의 수를 세기 위해 이전 값과 같은 경우에만 진행하도록 한다.
          if (!ignoreRG && (map[nr][nc] !== map[r][c])) continue;
  
          if (ignoreRG && (
            map[r][c] === 'B' && map[nr][nc] === 'R' ||
            map[nr][nc] === 'B' && map[r][c] === 'G' ||
            map[r][c] === 'R' && map[nr][nc] === 'B' ||
            map[nr][nc] === 'G' && map[r][c] === 'B'
          )) continue;
  
          visited[nr][nc] = true;
  
          que.push({
            r: nr,
            c: nc,
          });
        }
      }

      ++areaCnt;
    }
  }

  return areaCnt;
};

console.log(`${go(false)} ${go(true)}`);