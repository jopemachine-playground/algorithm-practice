const fs = require('fs');
const [n, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [n, ...inputs] = `
// 5
// -5 -2
// -3 0
// 2 5
// 6 10
// 8 12
// `.trim().split("\n");

const N = +n;
const nums = inputs.map(input => input.split(' ').map(e => +e));

let x = nums[0][0], y = nums[0][1];

let result = 0;

for (let i = 1; i < N; ++i) {
  const nx = nums[i][0];
  const ny = nums[i][1];

  // 선분이 겹치지 않는 경우
  if (nx > y) {
    result += y - x;
    x = nx;
    y = ny;
  }
  // 선분이 겹치는 경우 ny가 y 값보다 크다면 갱신, 그렇지 않은 경우 무시
  else if (y < ny) {
    y = ny;
  }
}

// 마지막 선분의 길이를 더해준다.
result += y - x;

console.log(result);