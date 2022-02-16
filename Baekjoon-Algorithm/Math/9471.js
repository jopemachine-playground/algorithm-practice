const readline = require('readline');
const inputs = [];
// const inputs = `
// 5
// 1 4
// 2 5
// 3 11
// 4 123456
// 5 987654
// `.trim().split('\n');

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

const solve = () => {
  let T = inputs[0];
  inputs.slice(1).forEach((input) => {
    const [idx, M] = input.split(' ').map(e => +e);

    let prev = 0;
    let next = 1;
    
    const prevStart = prev;
    const nextStart = next;
    
    let period = -1;
    // 우선 주기를 찾는다.
    for (let i = 2; true; ++i) {
      let nextTemp = (next + prev) % M;
      prev = next;
      next = nextTemp;
      if (prev === prevStart && next === nextStart) {
        period = i - 1;
        break;
      }
    }

    console.log(`${idx} ${period}`);
  });
};

// solve();