const fs        = require('fs');
// const [A, B]    = `100 40021`.trim().split(' ').map(e => +e);
const [A, B]    = fs.readFileSync("/dev/stdin").toString().trim().split(' ').map(e => +e);

const go = (num) => {
  if (num > B) return Infinity;
  if (num === B) {
    return 1;
  }

  // paths.push(num);
  const cand1 = 1 + go(num * 2);
  // paths.pop();

  // paths.push(num);
  const cand2 = 1 + go(num * 10 + 1);
  // paths.pop();

  return Math.min(cand1, cand2);
}

const res = go(A);
console.log(res === Infinity ? -1 : res);
