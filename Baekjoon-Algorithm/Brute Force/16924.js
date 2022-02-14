const fs = require('fs');
const [first, ...inputs] = `
6 8
....*...
...**...
..*****.
...**...
....*...
........
`.trim().split("\n");
// const [first, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, M] = first.split(' ').map(e => +e);

const deltas = [
  { r: 0, c: -1 },
  { r: 0, c: 1 },
  { r: 1, c: 0 },
  { r: -1, c: 0 },
];

const visited = Array.from(Array(N), () => Array(M).fill(false));

// 중심점 r,c 에서 부터 최대 몇 개까지의 십자가를 만들 수 있는지 리턴.
const countCross = (r, c) => {
  let size = 0;

  while (true) {
    let canMake = true;

    for (const delta of deltas) {
      const nr = r + delta.r * (1 + size);
      const nc = c + delta.c * (1 + size);

      if (nr >= N || nc >= M || nr < 0 || nc < 0) {
        canMake = false;
        break;
      }

      if (inputs[nr][nc] === '.') {
        canMake = false;
        break;
      }
    }

    if (canMake) {
      for (const delta of deltas) {
        const nr = r + delta.r * (1 + size);
        const nc = c + delta.c * (1 + size);
        visited[nr][nc] = true;
      }

      ++size;
    } else {
      break;
    }
  }

  if (size > 0) {
    visited[r][c] = true;
  }

  return size;
}

const result = [];

for (let i = 0; i < N; ++i) {
  for (let j = 0; j < M; ++j) {
    if (inputs[i][j] === '*') {
      const res = countCross(i, j);
      if (res > 0) {
        result.push({
          r: i,
          c: j,
          size: res,
        });
      }

      // 아래처럼 풀면 k가 N*M 까지 이기 때문에 시간초과가 뜬다.
      // countCross는 어차피 모든 점에 대해 호출해 볼 것이고 visited 정보를 유지하기 때문에
      // 굳이 바깥 반복문을 돌릴 필요는 없다.

      // if (res > 0) {
      //   for (let k = 1; k <= res; ++k) {
      //     console.log('k: ', k);
      //     result.push({
      //       r: i,
      //       c: j,
      //       size: k,
      //     });
      //   }
      // }
    }
  }
}

const possible = () => {
  if (result.length === 0) return false;

  for (let i = 0; i < N; ++i) {
    for (let j = 0; j < M; ++j) {
      if (
        inputs[i][j] === '*' &&
        visited[i][j] === false
      ) return false;
    }
  }

  return true;
};

if (!possible()) {
  console.log(-1);
} else {
  console.log(result.length);

  for (const crossInfo of result) {
    console.log(`${crossInfo.r + 1} ${crossInfo.c + 1} ${crossInfo.size}`);
  }
}