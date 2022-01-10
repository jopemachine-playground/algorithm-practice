const fs = require('fs');
const [N, nums, M, querys] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [N, nums, M, querys] = `
// 5
// 6 3 2 10 -10
// 8
// 10 9 -5 2 3 4 5 -10
// `.trim().split('\n');

const find = (sortedArr, target, start = 0, end = sortedArr.length) => {
  const nextIdx = Math.floor((start + end) / 2);

  if (sortedArr[nextIdx] === target) {
    return nextIdx;
  }

  // 찾고자 하는 값 보다 작음. => 오른쪽을 보자
  if (sortedArr[nextIdx] < target) {
    if (nextIdx === start) return -1;
    return find(sortedArr, target, nextIdx, end);
  }

  // 찾고자 하는 값 보다 큼. => 왼쪽을 보자
  if (sortedArr[nextIdx] > target) {
    if (nextIdx === end) return -1;
    return find(sortedArr, target, start, nextIdx);
  }
}

const cardNums = nums.split(' ').map(num => +num).sort((a, b) => a > b ? 1 : -1);
const cardQuerys = querys.split(' ').map(num => +num);

for (const query of cardQuerys) {
  if (find(cardNums, query) !== -1) process.stdout.write('1 ');
  else process.stdout.write('0 ');
}