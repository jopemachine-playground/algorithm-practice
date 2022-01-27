const fs = require('fs');
// const [first, statement] = 
// `19
// 1-9-1-9-1-9-1-9-1-9`.trim().split("\n");

const [first, statement] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const arr = statement.split('');

const nums = arr.filter((val, idx) => idx % 2 === 0).map(e => +e);
const oprs = arr.filter((val, idx) => idx % 2 === 1);

const N = +first;

const oprsCnt = oprs.length;

const calc = (opr, num1, num2) => {
  switch (opr) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
  }
};

let result = -Infinity;

// 괄호를 중첩해서 못 씀 => 괄호가 연속으로 오는 경우만 빼 주면 된다.
const isValid = (i) => {
  for (let j = 0; j + 1 < oprs.length; ++j) {
    if ((i & (1 << j) && (i & (1 << j + 1)))) return false;
  }
  return true;
};

// 괄호 안에 연산자는 최대 1개 밖에 없기 때문에 연산자와 1:1 매칭이 가능.
// 따라서 비트마스크로 아래처럼 풀 수 있다.
for (let i = 0; i < (1 << oprsCnt); ++i) {
  const this_nums = [...nums];

  if (!isValid(i)) continue;

  // j 번째 위치에 괄호가 있는 경우 먼저 계산해둔다.
  for (let j = 0; j < oprsCnt; ++j) {
    if (i & (1 << j)) {
      // j, j + 1 위치의 두 숫자를 연산하고 0이나 1을 넣는다.
      this_nums[j] = calc(oprs[j], this_nums[j], this_nums[j + 1]);

      if (oprs[j] === '+' || oprs[j] === '-') {
        this_nums[j + 1] = 0;
      } else {
        this_nums[j + 1] = 1;
      }
    }
  }

  let res = this_nums[0];
  for (let j = 0; j < oprsCnt; ++j) {
    res = calc(oprs[j], res, this_nums[j + 1]);
  }
  
  result = Math.max(res, result);
}

console.log(result);