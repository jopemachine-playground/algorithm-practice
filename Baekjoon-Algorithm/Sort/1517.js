const fs = require('fs');
const [N, inputs] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
// const [N, inputs] = `
// 3
// 3 2 1`.trim().split('\n');

let ans = 0;
const arr = inputs.split(' ').map(input => +input);

const merge = (leftArr, rightArr) => {
  let i = 0, j = 0;
  const result = [];
  while (i < leftArr.length && j < rightArr.length) {
    if (leftArr[i] <= rightArr[j]) {
      result.push(leftArr[i]);
      ++i;
    } else {
      result.push(rightArr[j]);
      ans += leftArr.length - i;
      ++j;
    }
  }

  return [
    ...result,
    ...leftArr.slice(i),
    ...rightArr.slice(j)
  ];
};

const mergeSort = (arr) => {
  const mid = Math.floor(arr.length / 2);
  if (arr.length <= 1) {
    return arr;
  }

  const left = mergeSort(arr.slice(0, mid));
  const right = mergeSort(arr.slice(mid));

  return merge(left, right);
};

mergeSort(arr);

console.log(ans);