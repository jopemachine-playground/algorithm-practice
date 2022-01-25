const fs = require('fs');
const [first, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [first, ...inputs] = `
// 3 7
// 4 0 0 0 0 0 0
// 0 0 0 2 0 0 0
// 0 0 0 0 0 0 4
// `.trim().split('\n');

const [N, M] = first.split(' ').map(e => +e);
const map = inputs.map(input => input.split(' ').map(e => +e));

const cctvTypes = [1,2,3,4,5];

const findCCTVs = () => {
  let cctvs = [];
  for (let i = 0; i < N; ++i) {
    for (let j = 0; j < M; ++j) {
      if (cctvTypes.includes(map[i][j])) {
        cctvs.push({
          r: i,
          c: j
        });
      }
    }
  }
  return cctvs;
};

const cctvs = findCCTVs();

const deltas = [
  { r: 0, c: 1 },
  { r: 1, c: 0 },
  { r: 0, c: -1 },
  { r: -1, c: 0 },
];

// 각 cctv들의 방향을 저장
const dirs = Array(cctvs.length);

const checkRange = (r, c) => {
  return !(r < 0 || c < 0 || r >= N || c >= M);
};

const getRightAngle = (idx) => {
  if (idx === 0) return 3;
  if (idx === 1) return 0;
  if (idx === 2) return 1;
  if (idx === 3) return 2;
};

// 한 방향으로 벽이 나오거나 범위에서 벗어날 때 까지 탐색한다.
// (cctv는 통과 가능하다는 점 유의.)
const visitMap = (r, c, dr, dc, this_map) => {
  let dist = 1;
  while (true) {
    const nr = r + dr * dist;
    const nc = c + dc * dist;
    if (!checkRange(nr, nc)) break;
    if (this_map[nr][nc] === 6) break;
    this_map[nr][nc] = '#';

    ++dist;
  }
}

const findEmptys = () => {
  const this_map = inputs.map(input => input.split(' ').map(e => +e));

  for (let cctvIdx = 0; cctvIdx < cctvs.length; ++cctvIdx) {
    const cctv = cctvs[cctvIdx];
    const { r, c } = cctv;
    const cctvType = map[r][c];
    const { r: dr, c: dc } = deltas[dirs[cctvIdx]];

    if (cctvType === 1) {
      visitMap(r, c, dr, dc, this_map);
    }

    else if (cctvType === 2) {
      visitMap(r, c, dr, dc, this_map);
      visitMap(r, c, -dr, -dc, this_map);
    }

    else if (cctvType === 3) {
      visitMap(r, c, dr, dc, this_map);
      const ndIdx = getRightAngle(dirs[cctvIdx]);
      const { r: ndr, c: ndc } = deltas[ndIdx];
      visitMap(r, c, ndr, ndc, this_map);
    }

    else if (cctvType === 4) {
      visitMap(r, c, dr, dc, this_map);
      visitMap(r, c, -dr, -dc, this_map);
      const ndIdx = getRightAngle(dirs[cctvIdx]);
      const { r: ndr, c: ndc } = deltas[ndIdx];
      visitMap(r, c, ndr, ndc, this_map);
    }

    else if (cctvType === 5) {
      visitMap(r, c, dr, dc, this_map);
      visitMap(r, c, -dr, -dc, this_map);
      const ndIdx = getRightAngle(dirs[cctvIdx]);
      const { r: ndr, c: ndc } = deltas[ndIdx];
      visitMap(r, c, ndr, ndc, this_map);
      visitMap(r, c, -ndr, -ndc, this_map);
    }
  }

  // console.log('this_map: ', this_map);

  let res = 0;
  for (let i = 0; i < N; ++i) {
    for (let j = 0; j < M; ++j) {
      if (this_map[i][j] === 0) {
        ++res;
      }
    }
  }
  return res;
};

let minCnt = Infinity;

const go = (idx = 0) => {
  if (idx === cctvs.length) {
    minCnt = Math.min(minCnt, findEmptys());
    return;
  }
  
  // 모든 경우의 수를 돌려 보면서, idx 번째 cctv의 방향을 결정한다.
  for (let i = 0; i < deltas.length; ++i) {
    dirs[idx] = i;
    go (idx + 1);
    dirs[idx] = undefined;
  }
};

go();

console.log(minCnt);