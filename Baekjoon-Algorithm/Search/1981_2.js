const fs = require('fs');
const [first, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [first, ...inputs] = `
// 3
// 2 4 9
// 1 2 2
// 9 2 4
// `.trim().split("\n");

const N = +first;
const map = inputs.map(input => input.split(' ').map(e => +e));

const deltas = [
  { r: 0, c: 1, },
  { r: 0, c: -1, },
  { r: 1, c: 0, },
  { r: -1, c: 0, },
];

const go = (min, max) => {
  // 예외 처리.
  if (map[0][0] < min || map[0][0] > max) return false;
  const visited = Array.from(Array(N), () => Array(N).fill(false));

  const que = [];

  que.push({ r: 0, c: 0 });

  visited[0][0] = true;

  while (que.length > 0) {
    const {r, c} = que.shift();

    if (r === N - 1 && c === N - 1) {
      return true;
    }

    for (const delta of deltas) {
      const nr = r + delta.r;
      const nc = c + delta.c;
      if (nr >= N || nc >= N || nr < 0 || nc < 0) continue;
      if (visited[nr][nc]) continue;
      visited[nr][nc] = true;

      if (map[nr][nc] <= max && map[nr][nc] >= min) {
        que.push({
          r: nr,
          c: nc,
        });
      }
    }
  }

  return false;
};

const possible = (diff) => {
  for (let min = 0; min + diff <= 200; min++) {
    if (go(min, min + diff)) return true;
  }
  return false;
};

let left = 0;
let right = 200;
let ans = right;

while (left <= right) {
  let mid = Math.floor((left + right) / 2);

  if (possible(mid)) {
    right = mid - 1;
    ans = mid;
  } else {
    left = mid + 1;
  }
}

console.log(ans);
