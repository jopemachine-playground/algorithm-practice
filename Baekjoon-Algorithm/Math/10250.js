const readline = require('readline');
const inputs = [];
// const inputs = `
// 1
// 30 50 60
// `.trim().split('\n');

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

const solve = () => {
  // const T = +inputs[0];

  for (let i = 1; i < inputs.length; ++i) {
    const [H, W, N] = inputs[i].split(' ').map(e => +e);
    let r, c;

    c = Math.ceil(N / H);
    r = N % H === 0 ? H : N % H;

    if (c < 10) c = `0${c}`;

    console.log(`${r}${c}`);
  }
};

// solve();