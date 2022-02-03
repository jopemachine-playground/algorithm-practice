const fs = require('fs');
// const [n, ...inputs] = `
// 6
// 0 0 0 0 0 0
// 0 1 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// `.trim().split('\n');
const [n, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
const N = +n;
const map = inputs.map(input => input.split(' ').map(e => +e));

// 0 : 가로 방향으로 놓는 들어갈 수 있는 파이프의 갯수
// 1 : 세로 방향으로 놓는 들어갈 수 있는 파이프의 갯수
// 2 : 대각선 방향으로 놓는 들어갈 수 있는 파이프의 갯수
const dist =
  Array.from(Array(N), () =>
  Array.from(Array(N), () =>
  Array(3).fill(-1))
);

const check = (r, c) => {
  return r < N && c < N && map[r][c] === 0;
}

const checkDiag = (r, c) => {
  return r >= 1 && c >= 1 && r < N && c < N && map[r][c] === 0 && map[r - 1][c] === 0 && map[r][c - 1] === 0;
}

const go = (r, c, prevDeltaIdx) => {
  if (r === N - 1 && c === N - 1) {
    return 1;
  }

  let ans = dist[r][c][prevDeltaIdx];
  if (ans !== -1) return ans;
  ans = 0;

  // 이전 파이프가 가로 방향이었을 경우
  if (prevDeltaIdx === 0) {
    // -
    if (check(r, c + 1)) {
      ans += go(r, c + 1, 0);
    }
    // 대각
    if (checkDiag(r + 1, c + 1)) {
      ans += go(r + 1, c + 1, 2);
    }
  } 
  // 이전 파이프가 세로 방향이었을 경우
  else if (prevDeltaIdx === 1) {
    // |
    if (check(r + 1, c)) {
      ans += go(r + 1, c, 1);
    }
    // 대각
    if (checkDiag(r + 1, c + 1)) {
      ans += go(r + 1, c + 1, 2);
    }
  } 
  // 이전 파이프가 대각 방향이었을 경우
  else if (prevDeltaIdx === 2) {
    // -
    if (check(r, c + 1)) {
      ans += go(r, c + 1, 0);
    }
    // |
    if (check(r + 1, c)) {
      ans += go(r + 1, c, 1);
    }
    // 대각
    if (checkDiag(r + 1, c + 1)) {
      ans += go(r + 1, c + 1, 2);
    }
  }

  dist[r][c][prevDeltaIdx] = ans;

  return ans;
};

console.log(go(0, 1, 0));