const fs = require('fs');
// const [first, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [first, ...inputs] = `
5
3 4 11 8 7 
0 12 17 11 10 
13 19 12 15 6 
10 8 15 17 18 
6 0 15 1 8`.trim().split("\n");

const N = +first;
const map = inputs.map(input => input.split(' ').map(e => +e));

const deltas = [
  { r: 1, c: 0, },
  { r: 0, c: 1, },
  { r: -1, c: 0, },
  { r: 0, c: -1, },
];

// 키를 만들어 리턴. 아래 방식은 200 * 200 = 40000 개의 키를 리턴하기 때문에,
// 너무 비효율적이고 오래걸린다.
const getKey = (min, max) => {
  return `${min}@${max}`;
};

// 최댓값과 최솟값의 차이를 dist 이하로 만들면서 N, N에 도착할 수 있는 path가 있다면 true 리턴.
const possible = (dist) => {
  const visited = Array.from(Array(N), () => Array.from(Array(N), () => { return {} }));
  const que = [];

  que.push({
    r: 0,
    c: 0,
    max: map[0][0],
    min: map[0][0],
  });

  visited[0][0][getKey(map[0], map[0])] = true;

  while (que.length > 0) {
    const { r, c, max, min } = que.shift();

    if (r === N - 1 && c === N - 1) {
      return true;
    }

    for (const delta of deltas) {
      const nr = r + delta.r;
      const nc = c + delta.c;
      if (nr >= N || nc >= N || nr < 0 || nc < 0) continue;

      const key = getKey(min, max);

      if (visited[nr][nc][key]) continue;
      visited[nr][nc][key] = true;

      const nmax = Math.max(max, map[nr][nc]);
      const nmin = Math.min(min, map[nr][nc]);

      if (nmax - nmin <= dist) {
        que.push({
          r: nr,
          c: nc,
          max: nmax,
          min: nmin,
        });
      }
    }
  }

  return false;
};

let left = 0;
let right = 200;
let result;

while (left <= right) {
  let mid = Math.floor((left + right) / 2);
  
  if (possible(mid)) {
    right = mid - 1;
    result = mid;
  } else {
    left = mid + 1;
  }
}

console.log(result);