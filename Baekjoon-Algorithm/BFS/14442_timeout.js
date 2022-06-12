const fs                = require('fs');
const [first, ...map]   = fs.readFileSync("/dev/stdin")
                            .toString()
                            .trim()
                            .split('\n')

// const [first, ...map] = `
// 6 4 1
// 0100
// 1110
// 1000
// 0000
// 0111
// 0000
// `.trim().split('\n');

const [N, M, K] = first.split(' ').map(str => Number(str));

const visited =
  Array.from(Array(N), () =>
  Array.from(Array(M), () =>
  Array(K).fill(false))
);

// 가능한 이동 방향
const deltas = [
  {x: 0, y: 1},
  {x: 1, y: 0},
  {x: -1, y: 0},
  {x: 0, y: -1},
];

const breakLimit = K;

const go = () => {
  const que = [
    {
      x: 0, y: 0,
      breakCount: 0,
      // 시작 칸도 센다.
      moveCount: 1,
    }
  ];

  let minDist = -1;

  while (que.length !== 0) {
    const top = que.shift();
    if (top.x === N - 1 && top.y === M - 1) {
      minDist = top.moveCount;
      break;
    }

    for (const delta of deltas) {
      const nx = top.x + delta.x;
      const ny = top.y + delta.y;
      const breakCount = top.breakCount;
      const moveCount = top.moveCount;

      // 범위 초과
      if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;

      // 방문한 적 있으면 패스
      if (visited[nx][ny][breakCount]) continue;
      visited[nx][ny][breakCount] = true;

      // 벽이 있는 경우
      if (map[nx][ny] === '1') {
        // 아직 벽을 부수지 않은 경우 부술 수 있다.
        if (breakCount < breakLimit) {
          que.push({
            x: nx, y: ny,
            breakCount: breakCount + 1,
            moveCount: moveCount + 1
          });
        }
      } else {
        que.push({
          x: nx, y: ny,
          breakCount,
          moveCount: moveCount + 1
        });
      }
    }
  }

  return minDist;
};

console.log(go());
