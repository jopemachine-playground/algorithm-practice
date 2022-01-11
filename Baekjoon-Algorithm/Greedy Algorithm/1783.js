// 처음에 문제를 방문할 수 있는 모든 칸의 갯수를 구하라고 잘못 이해했다.
// 이런 식으로 문제를 아예 잘못 이해 하면 완전 꼬이게 되기 때문에..
// 문제를 제대로 이해하고 풀어야 한다.

const fs = require('fs');
// N이 높이, M이 너비
const [N, M] = fs.readFileSync("/dev/stdin").toString().trim().split(" ").map(e => +e);
// const [N, M] = `
// 2 7
// `.trim().split(' ').map(e => +e);

const get = () => {
  if (N === 1) {
    return 1;
  }

  if (N === 2) {
    return Math.min(4, Math.ceil(M / 2));
  }

  // 높이가 3 이상인데 너비가 7보다 크면 모든 연산을 한 번씩 수행해야 한다. (4번 이상의 연산을 수행할 수 있기 때문)
  if (M >= 7) {
    return 5 + (M - 7);
  }

  // 높이가 3 이상인데 너비가 7 미만인 경우 각 연산을 1번 씩 수행할 수 없으므로 
  // 너비만큼 방문 가능한데, 4번만큼 까지만 가능함.
  else {
    return Math.min(4, M);
  }
}

console.log(get());