const fs = require('fs');
const [N, ...heights] = fs.readFileSync("/dev/stdin").toString().trim().split('\n').map(str => Number(str));

const getSafeBinaryFunc = (func) => (a, b, ...args) => {
  if (a === undefined && b === undefined) return undefined;
  if (a === undefined) return b;
  if (b === undefined) return a;

  return func(a, b, ...args);
}

const getMax = getSafeBinaryFunc(Math.max);
const getMin = getSafeBinaryFunc(Math.min);

const solve = (left = 0, right = heights.length - 1) => {
  if (left === right) return heights[left];
  let mid = Math.floor((left + right) / 2);
  let area = getMax(solve(left, mid), solve(mid + 1, right));

  let [lo, hi] = [mid, mid + 1];

  let height = getMin(heights[lo], heights[hi]);

  area = getMax(area, height * 2);

  while(lo > left || hi < right) {
    if (hi < right && (lo === left || heights[lo - 1] < heights[hi + 1])) {
      height = getMin(heights[++hi], height);
    } else {
      height = getMin(heights[--lo], height);
    }

    area = getMax(height * (hi - lo + 1), area);
  }

  return area;
};

console.log(solve());