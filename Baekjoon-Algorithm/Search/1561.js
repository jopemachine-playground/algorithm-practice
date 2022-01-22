const fs = require('fs');
const [first, second] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [first, second] = `
// 24 5
// 1 2 2 4 4`.trim().split("\n");

const [N, M] = first.split(' ').map(e => +e);
const nums = second.split(' ').map(e => +e);

let left = 0;
// N * 최대 운행 시간 (30분), 최대 20억 * 30 = 600억.
let right = N * 30;

// mid분에 타게 되는 아이들의 수
const getCounts = (mid) => {
  // 0분엔 모두가 타게됨. 
  let sum = M;
  
  for (let i = 0; i < nums.length; ++i) {
    sum += Math.floor(mid / nums[i]);
  }
  return sum;
};

// N < M 이면 그냥 마지막 놀이기구를 타면 된다
if (N < M) {
  console.log(N);
  process.exit(0);
}

// 마지막 아이까지 탔을 때 몇 분이 지났는지를 이분 탐색으로 구함.
let elapsed;
// elapsed분 지났을 때 까지 놀이기구를 탄 모든 사람의 수
let childs;
while (left <= right) {
  let mid = Math.floor((left + right) / 2);
  const childCnt = getCounts(mid);

  if (childCnt >= N) {
    elapsed = mid;
    childs = childCnt;
    right = mid - 1;
  } else {
    left = mid + 1;
  }
}

// console.log('childs: ', childs);
// console.log('elapsed', elapsed);

// elapsed분 지났을 때의 시작 값
let begin = getCounts(elapsed - 1) + 1;
// console.log('begin: ', begin);

let ans = 0;
for (let i = 0; i < nums.length && begin <= N; ++i) {
  if (elapsed % nums[i] === 0) {
    ans = i + 1;
    ++begin;
  }
}

console.log(ans);