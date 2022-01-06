const fs = require('fs');
const [N, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let priorityDict = [];
for (let i = 0; i < 26; ++i) priorityDict[i] = { priority: 0, value: '' };

inputs.forEach((input) => {
  for (let i = 0; i < input.length; ++i) {
    const chIdx = input[i].charCodeAt(0) - 'A'.charCodeAt(0);
    priorityDict[chIdx].value = input[i];
    priorityDict[chIdx].priority += 1 * Math.pow(10, input.length - i - 1);
  }
});

priorityDict.sort((i1, i2) => {
  return i1.priority < i2.priority ? 1 : -1;
});

const dict = {};

priorityDict.filter((item) => item.priority !== 0).forEach((item, idx) => {
  dict[item.value] = 9 - idx;
});

let sum = 0;
inputs.forEach((input) => {
  for (let i = 0; i < input.length; ++i) {
    sum += dict[input[i]] * Math.pow(10, input.length - i - 1);
  }
});

console.log(sum);
