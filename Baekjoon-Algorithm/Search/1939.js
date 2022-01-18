const fs = require('fs');
const [first, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [first, ...inputs] = `
// 5 5
// 1 2 5
// 2 3 4
// 1 3 3
// 1 4 3
// 4 5 1
// 5 1`.trim().split("\n");
const [N, M]        = first.split(' ').map(e => +e);
const mapInfos      = inputs.slice(0, inputs.length - 1).map(input => input.split(' ').map(e => +e));
const [src, dst]    = inputs[inputs.length - 1].split(' ').map(e => +e);

let min   = Infinity;
let max   = -Infinity;
// 개선점: N^2은 1억까지 커지는 데 M은 10만 까지 밖에 안 되니까 인접 리스트로 바꾸는게 바람직함.
const map = Array.from(Array(N + 1), () => []);

for (const mapInfo of mapInfos) {
  const [from, to, limit] = mapInfo;
  min = Math.min(min, limit);
  max = Math.max(max, limit);

  map[from][to] = map[from][to] ? Math.max(map[from][to], limit) : limit;
  map[to][from] = map[from][to];
}

let visited;

const initiailizeVisited = () => {
  visited = [];
  for (let i = 1; i <= N; ++i) {
    visited[i] = false;
  }
}

const reachable = (from, weight) => {
  if (from === dst) {
    return true;
  };
  
  visited[from] = true;
  
  for (const dest in map[from]) {
    const destIdx = +dest;
    if (map[from][destIdx] >= weight && !visited[destIdx]) {
      if (reachable (destIdx, weight)) {
        return true;
      }
    }
  }

  return false;
};

let start = min;
let end = max;

let ans = start;

while (start <= end) {
  initiailizeVisited();
  let mid = Math.floor((start + end) / 2);

  if (reachable(src, mid)) {
    start = mid + 1;
    ans = mid;
  } else {
    end = mid - 1;
  }
}

console.log(ans);