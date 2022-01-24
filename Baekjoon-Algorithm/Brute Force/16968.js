const fs = require('fs');
// const input = `dcdd`.toString().trim();
const input = fs.readFileSync("/dev/stdin").toString().trim();

const digitalCnt = 26;
const numberCnt = 10;

let result = 1;
let chBuf;
for (let i = 0; i < input.length; ++i) {
  const ch = input[i];

  if (ch === 'c') {
    if (chBuf === 'c') {
      result *= (digitalCnt - 1);
    } else {
      result *= digitalCnt;
    }
  }
  else if (ch === 'd') {
    if (chBuf === 'd') {
      result *= (numberCnt - 1);
    } else {
      result *= numberCnt;
    }
  }

  chBuf = ch;
}

console.log(result);