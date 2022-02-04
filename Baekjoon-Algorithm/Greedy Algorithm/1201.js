// Ref: 백준 알고리즘 강의 중급
const fs = require('fs');
// const [N, M, K] = `7 4 2`.split(" ").map(e => +e);
const [N, M, K] = fs.readFileSync("/dev/stdin").toString().trim().split(" ").map(e => +e);

const seq = Array.from(Array(N), (v, idx) => idx + 1);

// 이 경우가 아니라면 K, M으로 길이가 N인 수열을 만들 수 있다
if (N < M + K - 1 || N > M * K) {
  console.log(-1);
  process.exit(0);
}

const groupIdxes = [];
// 0 부터 K까지의 그룹을 무조건 포함시킴.
groupIdxes.push(0);
groupIdxes.push(K);

let remainingLength = N - K;
let remainingGroupCnts = M - 1;

let groupSize = remainingGroupCnts === 0 ? 1 :
  Math.floor(remainingLength / remainingGroupCnts);

let r = remainingGroupCnts === 0 ? 0 :
  (remainingLength % remainingGroupCnts);

while (remainingGroupCnts > 0) {
  const top = groupIdxes[groupIdxes.length - 1];
  if (r > 0) {
    groupIdxes.push(top + groupSize + 1);
    --r;
  } else {
    groupIdxes.push(top + groupSize);
  }

  --remainingGroupCnts;
}

let res = [];
// console.log('groupIdxes: ', groupIdxes);

for (let i = 0; i < groupIdxes.length; ++i) {
  res = [...res, ...seq.slice(groupIdxes[i], groupIdxes[i + 1]).reverse()];
}

console.log(res.join(' ').trim());
