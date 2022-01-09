const fs = require('fs');
const [N, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [N, ...inputs] = `
// 8
// 0 5 4 5 4 5 4 5
// 4 0 5 1 2 3 4 5
// 9 8 0 1 2 3 1 2
// 9 9 9 0 9 9 9 9
// 1 1 1 1 0 1 1 1
// 8 7 6 5 4 0 3 2
// 9 1 9 1 9 1 0 9
// 6 5 4 3 2 1 9 0
// `.trim().split('\n');

const getCombinations = (arr, r, selected = [], selectedIdx = 0, idx = 0) => {
  let result = [];
  if (r === 0) {
    return [[...selected]];
  } else if (idx < arr.length) {
    selected[selectedIdx] = arr[idx];
    result = [...result, ...getCombinations(arr, r - 1, selected, selectedIdx + 1, idx + 1)];
    result = [...result, ...getCombinations(arr, r, selected, selectedIdx, idx + 1)];
  }

  return result;
};

const map = inputs.map((lines) => lines.split(' ').map(e => +e));

const idxArr = [];
for (let i = 0; i < N; ++i) idxArr[i] = i;

const starts = getCombinations(idxArr, N / 2);

let min = Infinity;

for (const startTeamCase of starts) {
  let sSum = 0;
  let lSum = 0;

  const linkTeamCaseSet = new Set(idxArr);

  for (let i = 0; i < startTeamCase.length; ++i) {
    linkTeamCaseSet.delete(startTeamCase[i]);

    for (let j = 0; j < startTeamCase.length; ++j) {
      sSum += map[startTeamCase[i]][startTeamCase[j]];
    }
  }

  const linkTeamCase = Array.from(linkTeamCaseSet);

  for (let i = 0; i < linkTeamCase.length; ++i) {
    for (let j = 0; j < linkTeamCase.length; ++j) {
      lSum += map[linkTeamCase[i]][linkTeamCase[j]];
    }
  }

  min = Math.min(min, Math.abs(sSum - lSum));
}

console.log(min);