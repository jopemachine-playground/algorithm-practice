const fs = require('fs');
const [N, ...lines] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
// const [N, ...lines] = `
// 9
// 0 0 0 1 1 1 -1 -1 -1
// 0 0 0 1 1 1 -1 -1 -1
// 0 0 0 1 1 1 -1 -1 -1
// 1 1 1 0 0 0 0 0 0
// 1 1 1 0 0 0 0 0 0
// 1 1 1 0 0 0 0 0 0
// 0 1 -1 0 1 -1 0 1 -1
// 0 -1 1 0 1 -1 0 1 -1
// 0 1 -1 1 0 -1 0 1 -1`.trim().split('\n');

const map = lines.map(line => line.split(' '));

const check = (row, col, length) => {
  let allNeg1 = true;
  let allZero = true;
  let allPos1 = true;

  for (let i = row; i < row + length; ++i) {
    for (let j = col; j < col + length; ++j) {
      if (map[i][j] === '1') {
        allZero = false;
        allNeg1 = false;
      }
      else if (map[i][j] === '0') {
        allPos1 = false;
        allNeg1 = false;
      }
      else if (map[i][j] === '-1') {
        allPos1 = false;
        allZero = false;
      }
    }
  }

  return {
    allNeg1,
    allPos1,
    allZero
  }
}

let allNeg1Cnt = 0;
let allZeroCnt = 0;
let allPos1Cnt = 0;

const go = (row, col, length = N) => {
  const { allNeg1, allPos1, allZero } = check(row, col, length);

  // 더 이상 자르지 않음.
  if (allNeg1) {
    allNeg1Cnt++;
    return;
  }
  if (allPos1) {
    allPos1Cnt++;
    return;
  }
  if (allZero) {
    allZeroCnt++;
    return;
  }

  const unit = Math.floor(length / 3);

  // *..
  // ...
  // ...
  go (row, col, unit);

  // .*.
  // ...
  // ...
  go (row, col + unit, unit);
  
  // ..*
  // ...
  // ...
  go (row, col + 2 * unit, unit);

  // ...
  // *..
  // ...
  go (row + unit, col, unit);

  // ...
  // .*.
  // ...
  go (row + unit, col + unit, unit);

  // ...
  // ..*
  // ...
  go (row + unit, col + unit * 2, unit);

  // ...
  // ...
  // *..
  go (row + unit * 2, col, unit);

  // ...
  // ...
  // .*.
  go (row + unit * 2, col + unit, unit);

  // ...
  // ...
  // ..*
  go (row + unit * 2, col + unit * 2, unit);
};

go(0, 0, N);

console.log(allNeg1Cnt);
console.log(allZeroCnt);
console.log(allPos1Cnt);
