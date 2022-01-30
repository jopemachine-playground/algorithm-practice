const fs = require('fs');
// 범위: F층
// 시작: S층,
// 도착: G층,
// 위로: U칸 이동
// 아래로: D칸 이동
// const [F, S, G, U, D] = 
// `
// 10 1 10 2 1
// `
//   .trim()
//   .split(' ').map(e => +e);
const [F, S, G, U, D] = fs.readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(' ').map(e => +e);

const visited = Array(F + 1).fill(false);

const go = () => {
  const que = [];
  que.push({ floor: S, dist: 0 });

  while (que.length > 0) {
    const { floor, dist } = que.shift();
    if (floor > F || floor <= 0) continue;
    if (visited[floor]) continue;
    visited[floor] = true;

    if (floor === G) {
      return dist;
    }

    que.push({ 
      floor: floor + U,
      dist: dist + 1
    });
    que.push({
      floor: floor - D,
      dist: dist + 1
    });
  }

  return 'use the stairs';
};

console.log(go());
