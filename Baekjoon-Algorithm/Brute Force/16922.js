const fs = require('fs');
const N = Number(fs.readFileSync("/dev/stdin").toString().trim());
// const N = 1;

const res = new Set();

for (let i = 0; i <= N; ++i) {
  for (let v = 0; v <= N; ++v) {
    for (let l = 0; l <= N; ++l) {
      for (let x = 0; x <= N; ++x) {
        if (i + v + l + x === N) {
          const sum = i * 1 + v * 5 + l * 10 + x * 50;
          res.add(sum);
        }
      }
    }
  }
}

console.log(res.size);