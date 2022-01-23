const fs                  = require('fs');
// const [cnt, ...inputs]    = `
// 3
// 2 0 2
// 0 2 0
// 2 0 2`
//                       .trim()
//                       .split('\n');
const [cnt, ...inputs]    = fs.readFileSync("/dev/stdin")
                      .toString()
                      .trim()
                      .split('\n');

const N = +cnt;

let map;

const initializeMap = () => {
  map = inputs.map(input => input.split(' ').map(e => +e))
};

let merged = Array.from(Array(N), () => Array(N).fill(false));

const LIMIT = 5;

const deltas = [
  { r: 0, c: 1 },
  { r: 1, c: 0 },
  { r: 0, c: -1 },
  { r: -1, c: 0 },
];

const gen = (k) => {
  const res = Array(LIMIT);
  for (let i = 0; i < LIMIT; ++i) {
    res[i] = k % 4;
    k >>= 2;
  }
  return res;
};

// 블록 하나를 끝까지 움직임. 방향을 적절하게 simulate에서 맞춰서 호출해 줘야 한다.
const move = (sr, sc, r, c) => {
  let nr = sr, nc = sc;

  while (true) {
    if (nr + r < 0 || nc + c < 0 || nr + r >= N || nc + c >= N) break;
    if (merged[nr + r][nc + c]) break;

    if (map[nr + r][nc + c] === 0) {
      map[nr + r][nc + c] = map[nr][nc];
      map[nr][nc] = 0;
      nr += r;
      nc += c;
    }

    else if (map[nr + r][nc + c] === map[nr][nc]) {
      map[nr + r][nc + c] *= 2;
      map[nr][nc] = 0;
      merged[nr + r][nc + c] = true;
      nr += r;
      nc += c;
      break;
    }

    else {
      break;
    }
  }
};

const decideDirection = (r, c) => {
  let startC, startR;

  // 어느 쪽 방향에서 부터 move 해야할 지 결정한다.
  if (c === -1) {
    startC = 0;
    startR = 0;
  }
  if (c === 1) {
    startC = N - 1;
    startR = 0;
  }
  if (r === 1) {
    startC = 0;
    startR = N - 1;
  }
  if (r === -1) {
    startC = 0;
    startR = 0;
  }

  return {
    startR,
    startC,
  }
};

const simulate = (dir, debug) => {
  for (let i = 0; i < dir.length; ++i) {
    // 해당 r, c에서 합쳐졌는지를 나타냄.
    merged = Array.from(Array(N), () => Array(N).fill(false));

    if (debug) {
      console.log('-----------');
      console.log(map.map(e => e.join(' ')).join('\n'));
      console.log('-----------');
    }

    const { r, c } = deltas[dir[i]];
    let { startR, startC: sc } = decideDirection(r, c);
    let startC = sc;

    const isReversed_R = startR === N - 1;
    const isReversed_C = startC === N - 1;

    for (let j = 0; j < N; ++j) {
      for (let k = 0; k < N; ++k) {
        move(startR, startC, r, c);

        if (isReversed_C) startC -= 1;
        else startC += 1;
      }
      if (isReversed_R) startR -= 1;
      else startR += 1;
      startC = sc;
    }
  }
};

const getMaxValue = () => {
  let max = -Infinity;
  for (let j = 0; j < N; ++j) {
    for (let k = 0; k < N; ++k) {
      max = Math.max(max, map[j][k]);
    }
  }
  return max;
};

let result = -Infinity;
let maxAtIdx = -1;

for (let i = 0; i < (1 << LIMIT * 2); ++i) {
  initializeMap();
  // 움직이는 방향의 경우의 수들
  const dir = gen(i);
  simulate(dir);
  const maxVal = getMaxValue();

  if (result < maxVal) {
    result = maxVal;
    maxAtIdx = i;
  }
}

// 디버깅 용
const printMaxMap = () => {
  initializeMap();
  const dir = gen(maxAtIdx);
  simulate(dir, true);
}

// printMaxMap();
console.log(result);