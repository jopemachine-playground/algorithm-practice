const fs = require('fs');
const inputs = fs.readFileSync("/dev/stdin").toString().trim().split("\n").map(e => BigInt(e)).slice(1);
// const inputs = `
// 3
// -1
// 0
// 0
// `.trim().split("\n").map(e => BigInt(e));

inputs.sort((a, b) => {
  if (a > b) {
    return 1;
  } else if (a < b) {
    return -1;
  } else {
    return 0;
  }
});

let max = inputs[0];
let maxCnt = 1;
let cntBuffer = 1;

for (let i = 1; i < inputs.length; ++i) {
  if (inputs[i] === inputs[i - 1]) {
    cntBuffer++;
  } else {
    cntBuffer = 1;
  }

  if (maxCnt < cntBuffer) {
    max = inputs[i - 1];
    maxCnt = cntBuffer;
  }
}

console.log(max.toString());