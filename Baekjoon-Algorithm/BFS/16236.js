const fs                = require('fs');
// const [first, ...inputs]   = `
// 5
// 3 3 2 4 3
// 1 4 5 3 1
// 1 4 3 3 2
// 4 3 2 3 1
// 3 3 1 3 9`
//                             .trim()
//                             .split('\n')
const [first, ...inputs]   = fs.readFileSync("/dev/stdin")
                            .toString()
                            .trim()
                            .split('\n')
const N = +first;
const map = inputs.map(input => input.split(' ').map(e => +e));

let sharkStart;
let allFishes = [];

const deltas = [
  { r: 0, c: 1 },
  { r: 1, c: 0 },
  { r: 0, c: -1 },
  { r: -1, c: 0 },
];

const findAllFishes = () => {
  for (let i = 0; i < N; ++i) {
    for (let j = 0; j < N; ++j) {
      if (map[i][j] === 9) {
        sharkStart = { r: i, c: j };
      }
      else if (map[i][j] !== 0) {
        allFishes.push({
          r: i,
          c: j,
        });
      }
    }
  }
};

let visited;
let eatenFishes = Array.from(Array(N), () => Array(N));

const initVisited = () => {
  visited = Array.from(Array(N), () => Array(N));
};

const getDist = (sr, sc, dr, dc, size) => {
  const que = [];

  que.push({
    r: sr,
    c: sc,
    dist: 0,
  });

  while (que.length > 0) {
    const {r, c, dist} = que.shift();

    if (r === dr && c === dc) {
      // 먹으면 물고기 없어짐.
      map[r][c] = 0;
      return dist;
    }

    for (const delta of deltas) {
      const nr = delta.r + r;
      const nc = delta.c + c;
      if (nr >= N || nc >= N || nr < 0 || nc < 0) continue;
      if (visited[nr][nc]) continue;
      visited[nr][nc] = true;

      // 9는 상어의 시작 위치일 뿐 별 의미가 없으니 이동 가능함
      if (map[nr][nc] <= size || map[nr][nc] === 9) {
        que.push({
          r: nr,
          c: nc,
          dist: dist + 1
        });
      }
    }
  }
  
  return false;
};

const findNextFish = (sr, sc, size) => {
  let nr, nc, dist = Infinity;

  for (const fish of allFishes) {
    const { r: dr, c: dc } = fish;
    if (eatenFishes[dr][dc]) continue;
    if (size <= map[dr][dc]) continue;

    initVisited();
    const result = getDist(sr, sc, dr, dc, size);

    // 도달 가능한 점인 경우 거리를 재 보고 더 작은 경우 해당 물고기를 목표로 설정.
    if (result) {
      // 거리가 같은 경우
      if (dist === result) {
        // 더 상단 위쪽에 있는 물고기를 목표로 설정.
        if (dr < nr) {
          [nr, nc] = [dr, dc];
        }

        // 모두 같은 상단에 있다면 더 왼쪽에 있는 물고기를 목표로 설정
        if (dr === nr) {
          if (dc < nc) {
            [nr, nc] = [dr, dc];
          }
        }
      }

      if (dist > result) {
        [nr, nc] = [dr, dc];
        dist = result;
      }
    }
  }

  if (dist === Infinity) return false;

  return {
    nr, nc, dist
  };
};

const main = () => {
  findAllFishes();

  let { r: sr, c: sc } = sharkStart;
  let time = 0;
  let size = 2;
  let eat = 0;

  while (true) {
    const nextFishInfo = findNextFish(sr, sc, size);
    // console.log('nextFishInfo: ', nextFishInfo);

    // 먹을 수 있는 물고기가 더 없음.
    if (!nextFishInfo) break;
    const { nr, nc, dist } = nextFishInfo;

    time += dist;

    sr = nr;
    sc = nc;
    eatenFishes[nr][nc] = true;

    // 잡아 먹은 물고기가 크기가 같다면 상어 크기 1 증가
    if (++eat == size) {
      ++size;
      eat = 0;
    }
  }

  console.log(time);
};

main();