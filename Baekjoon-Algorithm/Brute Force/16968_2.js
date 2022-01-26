const fs = require('fs');
// const input = `dcdd`.toString().trim();
const input = fs.readFileSync("/dev/stdin").toString().trim();

let result = 1;
for (let i = 0; i < input.length; ++i) {
  let cnt = input[i] === 'c' ? 26 : 10;
  if (i > 0 && input[i] == input[i - 1]) {
    --cnt;
  }
  result *= cnt;
}

console.log(result);