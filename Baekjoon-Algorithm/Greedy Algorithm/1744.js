const fs = require('fs');
const [n, ...lines] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [n, ...lines] = `
// 2
// 1
// 1
// `.trim().split('\n');

const N = +n;
const nums = lines.map(e => +e);

const pos = nums.filter(e => e > 0).sort((a, b) => a < b ? 1 : -1);
const neg = nums.filter(e => e < 0).sort((a, b) => a > b ? 1 : -1);

// 0은 음수의 갯수가 홀수가 아니면 묶지 않는다. (그 외의 상황들에선 묶는 순간 값이 없어져서 결과 값이 작이지니까)
// 그렇기 때문에 0의 갯수는 중요하지 않고 있는지만 보면 된다.
const hasZero = nums.findIndex((val) => val === 0) === -1 ? false : true;

let sum = 0;

for (let i = 0; i < pos.length - 1; i += 2) {
  // 예외적으로 양수 1인 경우엔 곱하는 것보다 더해야 더 크다.
  if (pos[i + 1] === 1) {
    sum += (pos[i] + pos[i + 1]);
    continue;
  }
  sum += (pos[i] * pos[i + 1]);
}

// 홀수면 1개 남을 테니 그 아이를 더해준다.
if (pos.length % 2 === 1) sum += pos[pos.length - 1];

// 음수의 갯수가 홀수고 0이 있으면 어차피 1개가 남으니까, 가장 절댓값이 작은 음수를 0과 묶는다.
// 그렇게 하기 위해 배열의 마지막 숫자를 제거.
if (neg.length % 2 === 1 && hasZero) {
  neg.pop();
}

for (let i = 0; i < neg.length - 1; i += 2) {
  sum += (neg[i] * neg[i + 1]);
}

// 홀수면 1개 남을 테니 그 아이를 더해준다.
if (neg.length % 2 === 1) sum += neg[neg.length - 1];

console.log(sum);