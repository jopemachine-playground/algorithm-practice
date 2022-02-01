const readline = require('readline');
// const inputs = `
// 3
// 0 0 13 40 0 37
// 0 0 3 0 7 4
// 1 1 1 1 1 5`.trim().split('\n');

const inputs = [];

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

const solve = () => {
  const T = +inputs[0];
  const tests = inputs.slice(1);
  tests.map(test => {
    const [x1, y1, r1, x2, y2, r2] = test.split(' ').map(e => +e);
    const d = Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));

    // 두 원의 중심이 같은 경우 일치하거나 만나지 않는다.
    if (x1 === x2 && y1 === y2) {
      if (r1 === r2) {
        console.log(-1);
      } else {
        console.log(0);
      }
    } else {
      // 두 원이 내접하는 경우
      if (d === Math.abs(r2 - r1)) {
        console.log(1);
      } 
      // 한 원이 포함되는 경우
      else if (d < Math.abs(r2 - r1)) {
        console.log(0);
      } else {
        // 두 원이 외접하는 경우
        if (r1 + r2 === d) {
          console.log(1);
        }
        // 두 점에서 만남
        else if (r1 + r2 > d && d > Math.abs(r2 - r1)) {
          console.log(2);
        }
        // 만나지 않음
        else if (r1 + r2 < d) {
          console.log(0);
        }
      }
    }
  })
};

// solve();