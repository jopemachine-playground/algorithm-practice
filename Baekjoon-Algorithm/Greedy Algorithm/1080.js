// Ref: 백준 알고리즘 강의 중급
const fs = require('fs');
const [first, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [first, ...inputs] = 
// `3 4
// 0000
// 0010
// 0000
// 1001
// 1011
// 1001`.trim().split('\n');

const [N, M] = first.split(' ').map(e => +e);
const srcMap = inputs.map(input => input.split('').map(e => +e)).slice(0, N);
const dstMap = inputs.map(input => input.split('').map(e => +e)).slice(N);

const flipSrcMap = (row, col) => {
  if (row + 2 >= N || col + 2 >= M) throw new Error('Range error');
  for (let i = row; i < row + 3; ++i) {
    for (let j = col; j < col + 3; ++j) {
      // 1과 0 밖에 없는 경우, x = 1 - x 식으로 토글 효과를 낼 수 있다. (이게 더 빠름)
      srcMap[i][j] = 1 - srcMap[i][j];
    }
  }
};

let ans = 0;

// 3*3 행렬이 들어갈 수 있는 범위만큼만 돈다.
for (let i = 0; i < N - 2; ++i) {
  for (let j = 0; j < M - 2; ++j) {
    // 토글이 필요
    if (srcMap[i][j] !== dstMap[i][j]) {
      flipSrcMap(i, j);
      ++ans;
    }
  }
}

for (let i = 0; i < N; ++i) {
  for (let j = 0; j < M; ++j) {
    // 토글이 필요
    if (srcMap[i][j] !== dstMap[i][j]) {
      ans = -1;
    }
  }
}

console.log(ans);