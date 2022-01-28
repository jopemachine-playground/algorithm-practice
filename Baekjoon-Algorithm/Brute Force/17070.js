// 방법의 수는 항상 1,000,000보다 작거나 같다. 
// => 위 조건 때문에 브루트 포스로 풀 수 있다! 이 조건이 없으면 DP로 풀어야 됨!
const fs = require('fs');
// const [n, ...inputs] = `
// 6
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 1 0
// 0 0 1 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 1 0
// `.trim().split('\n');
const [n, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
const N = +n;
const map = inputs.map(input => input.split(' ').map(e => +e));

const check = (r, c) => {
  return r < N && c < N && map[r][c] === 0;
}

const checkDiag = (r, c) => {
  return r >= 1 && c >= 1 && r < N && c < N && map[r][c] === 0 && map[r - 1][c] === 0 && map[r][c - 1] === 0;
}

// dir을 주면 어차피 전에 어디서 왔는지 계산이 가능.
const go = (r, c, prevDeltaIdx) => {
  if (r === N - 1 && c === N - 1) {
    // 하나 찾음
    return 1;
  }

  let cnt = 0;
  // 오른쪽 파이프
  if (prevDeltaIdx === 0) {
    // 오른쪽으로 갈 수 있음
    if (check(r, c + 1)) {
      cnt += go (r, c + 1, 0);
    }
    // 대각선으로 갈 수 있음
    if (checkDiag(r + 1, c + 1)) {
      cnt += go (r + 1, c + 1, 2);
    }
  }

  // 수직 파이프
  else if (prevDeltaIdx === 1) {
    // 아래로 갈 수 있음
    if (check(r + 1, c)) {
      cnt += go(r + 1, c, 1);
    }

    // 대각선으로 갈 수 있음
    if (checkDiag(r + 1, c + 1)) {
      cnt += go(r + 1, c + 1, 2);
    }
  }

  // 대각선 파이프
  else if (prevDeltaIdx === 2) {
    // 아래로 갈 수 있음
    if (check(r + 1, c)) {
      cnt += go(r + 1, c, 1);
    }
    // 오른쪽으로 갈 수 있음
    if (check(r, c + 1)) {
      cnt += go (r, c + 1, 0);
    }
    // 대각선으로 갈 수 있음
    if (checkDiag(r + 1, c + 1)) {
      cnt += go(r + 1, c + 1, 2);
    }
  }

  return cnt;
}

console.log(go(0, 1, 0));