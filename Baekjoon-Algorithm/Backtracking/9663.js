// Ref : 백준 강의
const fs = require('fs');
const N = Number(fs.readFileSync("/dev/stdin"));
// const N = 15;

// 위에서 아래로 내려오면서 구하기 때문에 row 체크 불필요. 
const check_col   = [];
// => 대각선은 두 가지 방향만 검사하면 됨. (4가지 불필요)
// => 이 때 인덱스 만드는 게 중요한데, row + col, row - col으로 대각선 방향으로의 인덱스 생성 가능.
const check_dig1  = [];
const check_dig2  = [];

const check = (row, col) => {
  return !check_col[col] && !check_dig1[row + col] && !check_dig2[row - col]
};

const calc = (row) => {
  if (row === N) {
    return 1;
  }

  let cnt = 0;
  for (let col = 0; col < N; ++col) {
    if (check(row, col)) {
      [check_dig1[row + col], check_dig2[row - col], check_col[col]] = [true, true, true];
      cnt += calc(row + 1);
      [check_dig1[row + col], check_dig2[row - col], check_col[col]] = [false, false, false];
    }
  }
  
  return cnt;
}

console.log(calc(0));