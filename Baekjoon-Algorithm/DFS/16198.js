const fs            = require('fs');
const [n, inputs]   = fs.readFileSync("/dev/stdin")
                            .toString()
                            .trim()
                            .split('\n');
// const [n, inputs]   = `
// 4
// 1 2 3 4
// `
//                             .trim()
//                             .split('\n');

const N             = +n;
const nums          = inputs.split(' ').map(e => +e);

let ans = 0;

const go = (energy, remaining) => {
  // 2개 빼고 다 골랐을 때
  if (remaining.length === 2) {
    ans = Math.max(ans, energy);
    return;
  }

  for (let i = 1; i < remaining.length - 1; ++i) {
    const nextRemaining = [...remaining];
    nextRemaining.splice(i, 1);

    go(
      energy + (remaining[i - 1] * remaining[i + 1]),
      nextRemaining
    );
  }
};

go(0, nums);

console.log(ans);