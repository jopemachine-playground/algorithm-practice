// Ref : 백준 중급 알고리즘 강의
const fs          = require('fs');
const [cnt, S]    = fs.readFileSync("/dev/stdin")
                      .toString()
                      .trim()
                      .split('\n')
// const [cnt, S] = [
  // '4',
  // '2 1 2 7'
// ]

const usedNumbers = [];
const N = Number(cnt);
const nums = S.split(' ').map(str => Number(str));

// 비트 마스크로 표현한 모든 조합 케이스를 1<<N로 표현.
// 들어가고 안 들어가고 2배씩 늘어나기 때문에 재귀로 푸는 대신 이렇게 풀 수 있는 것. 
for (let i = 0; i < (1 << N); ++i) {
  let sum = 0;
  for (let j = 0; j < N; ++j) {
    // 비트 마스크로 표현했을 때, j번째 자릿수에 1이 있다면
    // 해당 값을 더하자.
    if (i & (1 << j)) {
      sum += nums[j];
    }
  }

  usedNumbers[sum] = true;
}

for (let i = 1;; ++i) {
  if (!usedNumbers[i]) {
    console.log(i);
    break;
  }
}
