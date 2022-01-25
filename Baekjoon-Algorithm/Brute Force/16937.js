const fs = require('fs');
const [first, n, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [first, n, ...inputs] = `
// 10 10
// 3
// 6 6
// 7 7
// 20 5
// `.trim().split("\n");
const [H, W] = first.split(' ').map(e => +e);
const N = +n;
const nums = inputs.map(input => input.split(' ').map(e => +e));

let max = 0;

const checkRange = (width, height) => {
  return width <= W && height <= H;
};

for (let i = 0; i < N; ++i) {
  for (let j = i + 1; j < N; ++j) {
    const [w1, h1] = nums[i];
    const [w2, h2] = nums[j];

    // 그대로 붙일 수 있는 경우
    const cond1 = checkRange(w1, h1) && checkRange(w2, h2) && (H - h1 >= h2 || W - w1 >= w2);
    // 첫 번째 스티커 회전
    const cond2 = checkRange(h1, w1) && checkRange(w2, h2) && (H - w1 >= h2 || W - h1 >= w2);
    // 두 번째 스티커 회전
    const cond3 = checkRange(w1, h1) && checkRange(h2, w2) && (H - h1 >= w2 || W - w1 >= h2);
    // 두 스티커 모두 회전
    const cond4 = checkRange(h1, w1) && checkRange(h2, w2) && (H - w1 >= w2 || W - h1 >= h2);

    if (cond1 || cond2 || cond3 || cond4) {
      max = Math.max(max, (w1 * h1) + (w2 * h2));
    }
  }
}

console.log(max);