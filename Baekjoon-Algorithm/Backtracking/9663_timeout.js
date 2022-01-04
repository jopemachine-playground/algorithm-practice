// Failed:: 시간 초과 => 시간 복잡도가 2^N^2로 매우 복잡하기 때문
const fs = require('fs');
const N = Number(fs.readFileSync("/dev/stdin"));
// const N = 15;

// n행의 가로 조건 확인
const c1 = [];
// n열의 세로 조건 확인
const c2 = [];

// 대각선 조건 확인
const c3 = [];
const c4 = [];

const check = (x, y) => {
  return !c1[x] && !c2[y] && !c3[x + y] && !c4[x - y];
};

let answer = 0;

const go = (idx = 0, queenCnt = 0) => {
  const x = Math.floor(idx / N);
  const y = idx % N;

  if (queenCnt === N) {
    answer += 1;
    return;
  }

  if (idx >= N * N) {
    return;
  }

  if (check(x, y)) {
    [c1[x], c2[y], c3[x + y], c4[x - y]] = [true, true, true, true];
    go (idx + 1, queenCnt + 1);
    [c1[x], c2[y], c3[x + y], c4[x - y]] = [false, false, false, false];
  }

  go (idx + 1, queenCnt);
}

go();

console.log(answer);