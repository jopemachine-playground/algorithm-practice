const fs        = require('fs');
const inputs    = fs.readFileSync("/dev/stdin")
                  .toString()
                  .trim()
                  .split('\n')
                  .slice(1)
                  .map((str) => str.split(' ').map(str => Number(str)));

// const inputs = [
//   '1234 3412',
//   '1000 1',
//   '1 16',
// ].map((str) => str.split(' ').map(str => Number(str)));

const execute_D = (src) => {
  return {
    next: (src.next << 1) % 10000,
    command: src.command + 'D',
  };
};

const execute_S = (src) => {
  return {
    next: src.next === 0 ? 9999 : src.next - 1,
    command: src.command + 'S',
  };
};

const execute_L = (src) => {
  const d1 = Math.floor(src.next / 1000);
  const d234 = (src.next % 1000) * 10;
  return {
    next: d234 + d1,
    command: src.command + 'L'
  };
};

const execute_R = (src) => {
  const d4 = (src.next % 10) * 1000;
  const d123 = Math.floor(src.next / 10);
  return {
    next: d4 + d123,
    command: src.command + 'R'
  };
};

const solve = (src, dst) => {
  const isTried = [];
  for (let i = 0; i < 10000; ++i) isTried[i] = false;

  const que = [];

  que.push({
    next: src,
    command: ''
  });

  while (que[0].next !== dst) {
    const next = que.shift();

    if (isTried[next.next]) continue;
    isTried[next.next] = true;

    que.push(execute_D(next));
    que.push(execute_S(next));
    que.push(execute_L(next));
    que.push(execute_R(next));
  }

  return que[0].command;
};

inputs.forEach((input) => {
  const [A, B] = input;
  console.log(solve(A, B));
});
