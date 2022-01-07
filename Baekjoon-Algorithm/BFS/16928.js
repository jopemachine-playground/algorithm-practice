const fs                    = require('fs');
const [first, ...inputs]    = fs.readFileSync("/dev/stdin")
                            .toString()
                            .trim()
                            .split('\n')
// const [first, ...inputs] = `
// 4 9
// 8 52
// 6 80
// 26 42
// 2 72
// 51 19
// 39 11
// 37 29
// 81 3
// 59 5
// 79 23
// 53 7
// 43 33
// 77 21`.trim().split('\n');

const [N, M]    = first.split(' ').map(e => +e);
const teleports = new Map;

inputs.forEach(input => {
  const [k, v] = input.split(' ').map(e => +e);
  teleports.set(k, v);
});

const visited = [];

for (let i = 0; i < 100; ++i) {
  visited[i] = false;
}

const go = () => {
  const que = [];

  let min = Infinity;
  que.push({ idx: 1, count: 0 });

  while(que.length > 0) {
    const { idx, count } = que.shift();
    if (idx === 100) {
      min = Math.min(min, count);
      break;
    }

    for (let dice = 1; dice <= 6; ++dice) {
      if (idx + dice <= 100) {
        const next = teleports.has(idx + dice) ? teleports.get(idx + dice) : idx + dice;

        if (!visited[next]) {
          que.push({ idx: next, count: count + 1 });
          visited[next] = true;
        }
      }
    }
  }

  return min;
};

console.log(go());