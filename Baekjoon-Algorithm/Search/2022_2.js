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

// 문제에서 소수점 세 자리 까지 정확도를 요구하기 때문에 1e-3 보다는 작아야 한다.
// 넉넉하게 1e-6 정도로 잡는 경우가 많은 것 같다.
while (Math.abs(left - right) > 1e-3) {
  let mid = (left + right) / 2;

  if (getC(mid) > c) {
    left = mid;
  } else {
    right = mid;
  }

  ans = mid;
}

console.log(ans.toFixed(3));