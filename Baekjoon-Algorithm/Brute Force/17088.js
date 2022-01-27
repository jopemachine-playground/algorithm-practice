const fs = require('fs');
const [n, input] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
// const [n, input] = 
// `4
// 24 21 14 10`.trim().split('\n');
const N = +n;
const nums = input.split(' ').map(e => +e);

// 첫 번째 항과 두 번째 항만 보면 공차가 결정된다.
// 즉, 공차의 후보들을 9가지 중 하나로 결정할 수 있다.
// 이 점을 이용하면 간단한 계산으로 연산 횟수의 최솟값을 구할 수 있다.
const diffCands = [];

// 예외 처리
if (nums.length === 1) {
  console.log(0);
  process.exit(0);
}

const getInitialCnt = (i, j) => {
  if (Math.abs(i) === 0 && Math.abs(j) === 0) return 0;
  if (Math.abs(i) === 1 && Math.abs(j) === 0) return 1;
  if (Math.abs(i) === 1 && Math.abs(j) === 1) return 2;
  if (Math.abs(i) === 0 && Math.abs(j) === 1) return 1;
};

// nums[0]
for (let i = -1; i <= 1; ++i) {
  // nums[1]
  for (let j = -1; j <= 1; ++j) {
    diffCands.push({
      diff: (nums[0] + i) - (nums[1] + j),
      nums0: nums[0] + i,
      nums1: nums[1] + j,
      initial: getInitialCnt(i, j),
    });
  }
}

let seq;

// nums를 해당 공차로 만들 수 있는지 체크하고, 가능한 경우 최소 연산 횟수를 리턴
const getMinOprCnt = (diff) => {
  let cnt = 0;

  // i + 1 번째 값을 순차적으로 하나하나 결정해 나감.
  for (let i = 0; i + 1 < N; ++i) {
    const actualDiff = seq[i] - seq[i + 1];

    if (diff - actualDiff === 1) {
      --seq[i + 1];
      ++cnt;
    } else if (diff - actualDiff === -1) {
      ++seq[i + 1];
      ++cnt;
    } else if (diff - actualDiff === 0) {
    } else {
      return Infinity;
    }
  }

  // console.log('seq: ', seq);

  return cnt;
}

let min = Infinity;
for (const cand of diffCands) {
  seq = [...nums];
  const {nums0, nums1, initial} = cand;
  seq[0] = nums0;
  seq[1] = nums1;

  min = Math.min(min, getMinOprCnt(cand.diff) + initial);
}

console.log(min === Infinity ? -1 : min);
