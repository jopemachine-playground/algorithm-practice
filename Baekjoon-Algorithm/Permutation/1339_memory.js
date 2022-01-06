const fs = require('fs');
const [N, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const inputs = [
//   'GCF',
//   'ACDEB'
// ];

const usedAlphabets = {};

for (const input of inputs) {
  for (let i = 0; i < input.length; ++i) {
    usedAlphabets[input[i]] = true;
  }
}

const getPermutations = (arr, idx = 0) => {
  let result = [];
  if (idx >= arr.length - 1) {
    return [[...arr]];
  }

  for (let i = idx; i < arr.length; ++i) {
    [arr[i], arr[idx]] = [arr[idx], arr[i]];
    result = [...result, ...getPermutations(arr, idx + 1)];
    [arr[i], arr[idx]] = [arr[idx], arr[i]];
  } 

  return result;
};

const alphabets = Object.keys(usedAlphabets);

const cands = getPermutations(alphabets);

const dicts = cands.map((cand) => {
  let dict = {};
  cand.forEach((val, idx) => {
    dict[val] = 9 - idx;
  });
  return dict;
});

let max = 0;
for (const dict of dicts) {
  let sum = 0;
  inputs.forEach((input) => {
    for (let i = 0; i < input.length; ++i) {
      sum += dict[input[i]] * Math.pow(10, input.length - i - 1);
    }
  });

  max = Math.max(max, sum);
}

console.log(max);