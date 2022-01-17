const fs = require('fs');
const inputs = fs.readFileSync("/dev/stdin").toString().trim().split(" ").map(e => +e);
// const inputs = `10 10 1`.trim().split(" ").map(e => +e);

const [x, y, c] = inputs; 

const getH1 = (k) => {
  return Math.sqrt(x * x - k * k);
}

const getH2 = (k) => {
  return Math.sqrt(y * y - k * k);
}

const getC = (k) => {
  const h1 = getH1(k);
  const h2 = getH2(k);
  return ((h1 * h2) / (h1 + h2));
};

let ans;
let left = 0;
let right = Math.max(x, y);

for (let i = 0; i < 10000; ++i) {
  let mid = (left + right) / 2;

  if (getC(mid) > c) {
    left = mid;
  } else {
    right = mid;
  }

  ans = mid;
}

console.log(ans.toFixed(3));