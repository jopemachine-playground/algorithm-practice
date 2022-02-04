const fs                  = require('fs');
// const [first, ...lines]   = `
// 14 4
// #...
// ....
// ###.
// ....
// ...#
// o#.#
// #.#.
// ..#.
// ..#.
// o..#
// ...#
// ..#.
// ....
// ...#
// `
//                             .trim()
//                             .split('\n');
const [first, ...lines]   = fs.readFileSync("/dev/stdin")
                            .toString()
                            .trim()
                            .split('\n');

const [N, M] = first.split(' ').map(e => +e);

let map;
const initializeMap = () => {
  map = lines.map((line) => line.split(''));
};

const findStartPts = () => {
  const pts = [];
  for (let i = 0; i < N; ++i) {
    for (let j = 0; j < M; ++j) {
      if (lines[i][j] === 'o') {
        pts.push({ r: i, c: j });
        if (pts.length === 2) break;
      }
    }
    if (pts.length === 2) break;
  }
  return pts;
};

const gen = (k) => {
  const result = [];
  for (let i = 0; i < 10; ++i) {
    const dir = k % 4;
    k >>= 2;
    result.push(dir);
  }
  return result;
};

const starts = findStartPts();

const deltas = [
  { r: 0, c: 1 },
  { r: 0, c: -1 },
  { r: 1, c: 0 },
  { r: -1, c: 0 },
];

const move = (coin, delta) => {
  const { r, c } = delta;
  const nr = coin.r + r;
  const nc = coin.c + c;

  let isDropped = false;

  if (nr >= N || nc >= M || nr < 0 || nc < 0) {
    isDropped = true;
    map[coin.r][coin.c] = '.';
    coin.r = -1;
    coin.c = -1;
  } else if (map[nr][nc] === '.') {
    [map[nr][nc], map[coin.r][coin.c]] = ['o', '.'];
    coin.r = nr;
    coin.c = nc;
  }

  return isDropped;
}

const simulate = (dirs) => {
  let [s1, s2] = [{ ...starts[0] }, { ...starts[1] }];

  for (let dist = 0; dist < dirs.length; ++dist) {
    const dir = dirs[dist];
    const delta = deltas[dir];

    // 어차피 동전은 겹쳐지기 때문에 움직이는 순서는 중요하지 않다, 이 점이 구슬 탈출 문제와 다름.
    const firstDropped = move(s1, delta);
    const secondDropped = move(s2, delta);

    // 둘 다 떨어지는 경우 실패
    if (firstDropped && secondDropped) return Infinity;
    // 한 개만 떨어뜨릴 수 있다면 성공
    if (firstDropped || secondDropped) return dist + 1;
  }

  // console.log('--------------------------------');
  // console.log('dirs: ', dirs);
  // console.log(map.map(o => o.join(' ')).join('\n'));
  // console.log('--------------------------------');

  return Infinity;
};

let min = Infinity;

// 모든 경우의 수 생성 후, 의미 없는 경우들은 제외하고 대입해 보기.
// 최대 10번, 각각 4번 씩 분기되니 4^10 = 2^20번 순회 필요.
for (let i = 0; i < (1 << 20); ++i) {
  const dirs = gen(i);
  initializeMap();
  min = Math.min(min, simulate(dirs));
}

console.log(min === Infinity ? -1 : min);
