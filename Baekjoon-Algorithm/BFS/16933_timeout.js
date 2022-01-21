const fs                    = require('fs');
const [first, ...inputs]    = fs.readFileSync("/dev/stdin")
                            .toString()
                            .trim()
                            .split('\n');
// const [first, ...inputs] = `
// 6 4 1
// 0100
// 1110
// 1000
// 0000
// 0111
// 0000
// `.trim().split('\n');

const [N, M, K] = first.split(' ').map(e => +e);

const map = inputs.map(input => input.split('').map(e => +e));

const cache = 
  Array.from(Array(N), () =>
  Array.from(Array(M), () =>
  Array.from(Array(K + 1), () =>
  Array(2).fill(false)))
);

const deltas = [
  { r: 0, c: 0 },
  { r: 0, c: 1 },
  { r: 0, c: -1 },
  { r: 1, c: 0 },
  { r: -1, c: 0 },
];

const go = () => {
  const que = [];

  // 시작 칸도 포함하므로 move는 1에서 시작
  que.push({ r: 0, c: 0, move: 1, breakCount: 0, isDay: 1, /* paths: [] */ });

  while (que.length > 0) {
    const { r, c, move, breakCount, isDay, /* paths */ } = que.shift();

    if (r === N - 1 && c === M - 1) {
      // console.log(paths)
      return move;
    }

    for (const delta of deltas) {
      const nr = delta.r + r;
      const nc = delta.c + c;
      // 범위 초과
      if (nr >= N || nr < 0 || nc >= M || nc < 0) continue;

      // 낮에 벽을 만났고, 벽을 더 부술 수 있는 경우
      if (isDay && map[nr][nc] === 1 && breakCount < K) {
        // 이동해본 곳이 아니라면 벽을 부수고 이동

        if (!cache[nr][nc][breakCount][isDay]) {
          cache[nr][nc][breakCount][isDay] = true;

          que.push({
            r: nr,
            c: nc,
            breakCount: breakCount + 1,
            isDay: 1 - isDay,
            move: move + 1,
            // paths: [...paths, { nr, nc }]
          });
        }
      }
      else {
        // 벽이 없으면 자유롭게 이동하거나 머무름.
        if (map[nr][nc] === 0 || (r == nr && c == nc)) {
          // 이동해본 곳이 아니라면 이동

          if (!cache[nr][nc][breakCount][isDay]) {
            cache[nr][nc][breakCount][isDay] = true;

            que.push({
              r: nr,
              c: nc,
              breakCount,
              isDay: 1 - isDay,
              move: move + 1,
              // paths: [...paths, { nr, nc }]
            });
          }
        }
      }
    }
  }
};

console.log(go() ?? -1);