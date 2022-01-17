const fs = require('fs');
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const input = `
// 6
// 1 2 3 4 5 6
// 2 1 1 1
// `.trim().split('\n');

const N = Number(input[0]);
const Nums = input[1].split(' ').map(e => +e);
// 각 연산자들의 최대 사용 개수
const [max_plu, max_min, max_mul, max_div] = input[2].split(' ').map(e => +e);

let minValue = Infinity;
let maxValue = -Infinity;

const calc = (picked) => {
  let res = Nums[0];

  for (let i = 0; i < picked.length; ++i) {
    const oper = picked[i];
    switch (oper) {
      case '+':
        res += Nums[i + 1];
        break;
      case '-':
        res -= Nums[i + 1];
        break;
      case '*':
        res *= Nums[i + 1];
        break;
      case '/':
        res = res < 0 ? -Math.floor(-res / Nums[i + 1]) : Math.floor(res / Nums[i + 1]);
        break;
      default:
        throw new Error('Not allowed oper', oper);
    }
  }

  maxValue = Math.max(maxValue, res);
  minValue = Math.min(minValue, res);
};

const go = (picked = [], plu = 0, min = 0, mul = 0, div = 0) => {
  const idx = picked.length;

  if (idx === N - 1) {
    calc(picked);
  }

  if (plu < max_plu) {
    picked.push('+');
    go(picked, plu + 1, min, mul, div);
    picked.pop();
  }

  if (min < max_min) {
    picked.push('-');
    go(picked, plu, min + 1, mul, div);
    picked.pop();
  }

  if (mul < max_mul) {
    picked.push('*');
    go(picked, plu, min, mul + 1, div);
    picked.pop();
  }

  if (div < max_div) {
    picked.push('/');
    go(picked, plu, min, mul, div + 1);
    picked.pop();
  }
};

go();

if (maxValue == 0) maxValue = 0;
if (minValue == 0) minValue = 0;

console.log(maxValue);
console.log(minValue);