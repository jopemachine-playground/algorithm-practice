const fs = require('fs');
// const [first, ...inputs] = `
// 7 4
// 2 1
// 3 6
// 5 1
// 1 7`.trim().split('\n');
const [first, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
const [N, M] = first.split(' ').map(e => +e);

const friends = inputs.map(input => input.split(' ').map(e => +e));
const isFriends = Array.from(Array(N + 1), () => Array(N + 1).fill(false));

friends.forEach((friendInfo) => {
  const [src, dst] = friendInfo;
  isFriends[src][dst] = isFriends[dst][src] = true;
});

const getFriendsCnt = (idx) => {
  return isFriends[idx].filter((val) => val === true).length;
};

let min = Infinity;

// N^3 처럼 보이지만 그렇지 않음에 주의
// i, j가 친구일 때만 아래 반복문이 실행되고, 아래 반복문은 최대 M번까지만 호출되고, 각각의 경우 N번만큼 실행되므로
// O(N^2 + MN)이 된다.
for (let i = 1; i <= N; ++i) {
  for (let j = i + 1; j <= N; ++j) {
    if (!isFriends[i][j]) continue;
    for (let k = j + 1; k <= N; ++k) {
      if (!isFriends[i][k] || !isFriends[j][k]) continue;

      const sum = (getFriendsCnt(i) - 2) + (getFriendsCnt(j) - 2) + (getFriendsCnt(k) - 2);
      min = Math.min(sum, min);
    }
  }
}

console.log(min === Infinity ? -1 : min);