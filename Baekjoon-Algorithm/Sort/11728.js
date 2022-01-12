const fs = require('fs');
const [NM, first, second] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [NM, first, second] = `
// 4 3
// 2 3 5 9
// 1 4 7
// `.trim().split("\n");

const [N, M] = NM.split(' ').map(e => +e);
const arr1 = first.split(' ').map(e => +e);
const arr2 = second.split(' ').map(e => +e);

let i = 0;
let j = 0;
let result = [];

while (i < N && j < M) {
  if (arr1[i] >= arr2[j]) {
    result.push(arr2[j]);
    ++j;
  } else {
    result.push(arr1[i]);
    ++i;
  }
}

result = [...result, ...arr1.slice(i), ...arr2.slice(j)];

console.log(result.join(' '));