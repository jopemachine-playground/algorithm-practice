let fs = require('fs');
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const tests = input.slice(0, input.length - 1);

const lotta = [];

const go = (arr = [], pIdx = 0, arrIdx = 0) => {
  if (pIdx === 6) {
    process.stdout.write(lotta.join(' '));
    console.log();
    return;
  }

  if (arrIdx === arr.length) return;

  lotta.push(arr[arrIdx]);
  go(arr, pIdx + 1, arrIdx + 1);
  lotta.pop();
  go(arr, pIdx, arrIdx + 1);
};

tests.forEach((test, idx) => {
  const [k, ...S] = test.split(' ');
  go(S);

  if (idx !== tests.length - 1) console.log();
});