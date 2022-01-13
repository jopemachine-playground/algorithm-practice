const fs = require('fs');
// const N = +(fs.readFileSync("/dev/stdin").toString().trim());
const N = 9;

// 베이스 케이스에 해당하는 공백, 별 출력을 각각 따로 처리해줘야 함에 유의.
const star = (i, j, unit) => {
  // 베이스 케이스 처리 : 공백을 처리하는 조건에 유의.
  if (
    (Math.floor(i / unit)) % 3 === 1 &&
    (Math.floor(j / unit)) % 3 === 1
    ) {
    process.stdout.write(' ');
  }
  // 베이스 케이스 처리 (별)
  else if (Math.floor(unit / 3) === 0) {
    process.stdout.write('*');
  } 
  // 베이스 케이스가 아닌 경우엔 unit을 3씩 나눈다.
  else {
    star(i, j, Math.floor(unit / 3));
  }
};

for (let i = 0; i < N; ++i) {
  for (let j = 0; j < N; ++j) {
    star(i, j, N);
  }
  console.log();
}