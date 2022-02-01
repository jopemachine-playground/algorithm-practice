const readline = require('readline');
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
  for (let i = 1; i < T; ++i) {
    const [x, y] = inputs[i].split(' ').map(e => +e);
    const len = y - x + 1;

    // 처음 시작하는 값은 무조건 1로 고정
    let k = 1;
    while (k < len) {

    }
  }
};
