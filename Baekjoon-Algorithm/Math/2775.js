const readline = require('readline');
const inputs = [];
// const inputs = `
// 2
// 1
// 3
// 2
// 3
// `.trim().split('\n');

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

const solve = () => {
  const T = +inputs[0];

  for (let i = 1; i <= 2 * T; i += 2) {
    // k층 n호
    const [K, N] = [+inputs[i], +inputs[i + 1]];
    const res = Array.from(Array(K + 1), () => Array(N + 1).fill(0));
    for (let j = 1; j <= N; ++j) {
      res[0][j] = j;
    }

    // 1층 부터 K층 까지 계산
    for (let j = 1; j <= K; ++j) {
      let sum = 0;
      for (let k = 1; k <= N; ++k) {
        sum += res[j - 1][k];
        res[j][k] = sum;
      }
    }

    console.log(res[K][N]);
  }
};

// solve();