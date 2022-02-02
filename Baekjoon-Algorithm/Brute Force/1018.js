const readline = require('readline');
// const inputs = `
// 11 12
// BWWBWWBWWBWW
// BWWBWBBWWBWW
// WBWWBWBBWWBW
// BWWBWBBWWBWW
// WBWWBWBBWWBW
// BWWBWBBWWBWW
// WBWWBWBBWWBW
// BWWBWBWWWBWW
// WBWWBWBBWWBW
// BWWBWBBWWBWW
// WBWWBWBBWWBW
// `.trim().split('\n');
const inputs = [];

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

let map, initialMap;

const nestedCopy = (arr) => {
  return JSON.parse(JSON.stringify(arr));
};

const toggle = (color) => {
  return color === 'B' ? 'W' : 'B';
};

const getMinCost = (r, c, startShouldBe) => {
  let cost = 0;
  let shouldBe = startShouldBe;
  for (let i = 0; i < 64; ++i) {
    const nr = r + (Math.floor(i / 8));
    const nc = c + (i % 8);

    if (map[nr][nc] !== shouldBe) ++cost;
    // 행 넘어갈 때만 안 바꿔주면 된다.
    if (i % 8 !== 7) {
      shouldBe = toggle(shouldBe);
    }
  }

  return cost;
};

const solve = () => {
  const [N, M] = inputs[0].split(' ').map(e => +e);
  initialMap = inputs.slice(1).map(input => input.split(''));

  let min = Infinity;
  // 8*8 맵의 시작점 (왼쪽 상단)을 결정한다.
  for (let i = 0; i + 8 <= N; ++i) {
    for (let j = 0; j + 8 <= M; ++j) {
      map = nestedCopy(initialMap);
      min = Math.min(min, getMinCost(i, j, 'B'), getMinCost(i, j, 'W'));
    }
  }

  console.log(min);
};

// solve();