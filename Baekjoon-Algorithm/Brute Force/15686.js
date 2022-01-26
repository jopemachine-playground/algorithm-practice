const fs = require('fs');
const [first, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [first, ...inputs] = `
// 5 3
// 0 0 1 0 0
// 0 0 2 0 1
// 0 1 2 0 0
// 0 0 1 0 0
// 0 0 0 0 2
// `.trim().split('\n');

const [N, M] = first.split(' ').map(e => +e);
let map;

const initializeMap = () => {
  map = inputs.map(input => input.split(' ').map(e => +e));
};

const findAllPoints = () => {
  const houses = [];
  const stores = [];
  for (let i = 0; i < N; ++i) {
    for (let j = 0; j < N; ++j) {
      if (map[i][j] === 1) {
        houses.push({
          r: i, c: j
        });
      }
      if (map[i][j] === 2) {
        stores.push({
          r: i, c: j
        });
      }
    }
  }
  return [houses, stores];
};

const printMap = () => {
  console.log('--------------------------------');
  for (let i = 0; i < N; ++i) {
    for (let j = 0; j < N; ++j) {
      process.stdout.write(map[i][j] + ' ');
    }
    console.log();
  }
};

initializeMap();
const [houses, stores] = findAllPoints();

let result = Infinity;
const currStoreLen = stores.length;

// 최대 M개의 store를 남겨둬야 하니 store가 M개를 초과하는 경우 false 반환
const isValid = (num) => {
  let cnt = 0;
  for (let j = 0; j < currStoreLen; ++j) {
    if ((num & (1 << j)) === 0) {
      ++cnt;
      if (cnt > M) return false;
    }
  }

  return true;
};

// 모든 경우를 생성. 치킨집이 최소한 1개는 나와야 하므로 1 빼 주면 된다.
for (let i = 0; i < ((1 << currStoreLen) - 1); ++i) {
  initializeMap();
  if (!isValid(i)) continue;

  let removedStores = Array(currStoreLen).fill(false);
  for (let j = 0; j < currStoreLen; ++j) {
    // 1이 나오면, 해당 치킨집을 폐지하는 경우
    if (i & (1 << j)) {
      const { r, c } = stores[j];
      map[r][c] = 0;
      removedStores[j] = true;
    }
  }

  let distSum = 0;
  // 치킨집을 해당하는 경우만큼 없애고 치킨 거리를 재 본다.
  for (let j = 0; j < houses.length; ++j) {
    let dist = Infinity;
    for (let k = 0; k < currStoreLen; ++k) {
      // 해당 치킨집이 없어진 경우 패스
      if (removedStores[k]) continue;
      const {r: sr, c: sc} = houses[j];
      const {r: dr, c: dc} = stores[k];
      
      dist = Math.min(dist, Math.abs(sr - dr) + Math.abs(sc - dc));
    }
    
    // 치킨집이 1개 이상 존재하는 한 나올 수 없음
    // if (dist !== Infinity) distSum += dist;
    distSum += dist;
  }

  // printMap();

  if (distSum === 0) distSum = Infinity;
  result = Math.min(distSum, result);
}

console.log(result);