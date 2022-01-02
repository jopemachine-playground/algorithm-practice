let fs = require('fs');
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

// const input = [`5 0`, `-7 -3 -2 5 8`];
// const input = [`2 -2`, `-1 -1`];

const [N, S] = input[0].split(' ').map(str => Number(str));

if (N === 0 && S === 0) {
  console.log(1);
  process.exit(0);
}

const Nums = input[1].split(' ').map(str => Number(str));

let caseCnt = 0;

const go = (idx, sum) => {
  if (idx >= N) {
    if (sum === S) {
      ++caseCnt;
    }
    return;
  }

  go(idx + 1, sum + Nums[idx]);
  go(idx + 1, sum);
};

go(0, 0);

if (S === 0) --caseCnt;

console.log(caseCnt);