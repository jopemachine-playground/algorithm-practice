const fs = require('fs');
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const getCombination = (arr, r, selected = [], arrIdx = 0, selectedIdx = 0) => {
  let result = [];
  if (r === 0) {
    return [...result, [...selected]];
  }
  if (arr.length <= arrIdx) return result;

  selected[selectedIdx] = arr[arrIdx];
  result = [...result, ...getCombination(arr, r - 1, selected, arrIdx + 1, selectedIdx + 1)];
  result = [...result, ...getCombination(arr, r, selected, arrIdx + 1, selectedIdx)];

  return result;
};

const [N, S] = input[0].split(' ').map(str => Number(str));

if (N === 0 && S === 0) {
  console.log(1);
  process.exit(0);
}

const Nums = input[1].split(' ').map(str => Number(str));
let caseCnt = 0;

for (let r = 1; r <= Nums.length; ++r) {
  for (const cand of getCombination(Nums, r)) {
    if (cand.reduce((curr, val) => curr + val, 0) === S) {
      ++caseCnt;
    }
  }
}

console.log(caseCnt);