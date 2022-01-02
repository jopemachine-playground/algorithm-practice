let fs = require('fs');
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const getCombination = (arr, r, selectedIdx = 0, arrIdx = 0, selected = []) => {
  let result = [];
  if (r === 0) {
    result.push([...selected]);
  } else if (arrIdx < arr.length) {
    selected[selectedIdx] = arr[arrIdx];
    result = [...result, ...getCombination(arr, r - 1, selectedIdx + 1, arrIdx + 1, selected)];
    result = [...result, ...getCombination(arr, r, selectedIdx, arrIdx + 1, selected)];
  }

  return result;
};

const tests = input.slice(0, input.length - 1);

tests.forEach((test, idx) => {
  const [k, ...S] = test.split(' ');
  const comb = getCombination(S, 6);
  comb.forEach((cand) => {
    process.stdout.write(cand.join(' '));
    console.log();
  });

  if (idx !== tests.length - 1) console.log();
});
