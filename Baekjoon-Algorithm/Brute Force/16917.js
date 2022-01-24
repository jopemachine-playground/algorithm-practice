const fs = require('fs');
// const [A, B, C, X, Y] = `1500 2000 500 90000 100000`.split(" ").map(e => +e);
const [A, B, C, X, Y] = fs.readFileSync("/dev/stdin").toString().trim().split(" ").map(e => +e);

const cands = [];

// 반반치킨을 가능한 사고 나머지를 개별로 구매
let res = Math.min(X, Y) * 2 * C;

if (X > Y) {
  res += (X - Y) * A;
} else {
  res += (Y - X) * B;
}

cands.push(res);

// 반반치킨 으로 다 삼. 나머지는 버림.
cands.push(Math.max(X, Y) * 2 * C);

// 반반치킨 값이 너무 비싼 경우:
// 반반치킨 안 삼
cands.push(A * X + B * Y);

console.log(Math.min(...cands));