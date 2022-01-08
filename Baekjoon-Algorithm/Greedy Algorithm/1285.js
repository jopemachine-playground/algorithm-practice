// Ref: 백준 알고리즘 강의 중급
const fs                = require('fs');
const [N, ...map]       = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [N, ...map] = `
// 3
// HHT
// THH
// THT
// `.trim().split('\n');

const flip = (val) => {
  return val === 'H' ? 'T' : 'H';
};

let min = Infinity;

const go = () => {
  // 각 행들을 flip 할 수 있는 모든 케이스들을 비트 마스크로 나타냄
  for (let i = 0; i < (1 << N); ++i) {
    let sum = 0;

    // 각 열들을 바꿀 수 있는 경우의 수 만 남게됨.
    for (let j = 0; j < N; ++j) {
      let tCount = 0;
      for (let k = 0; k < N; ++k) {
        if (i & (1 << k)) {
          if ((flip(map[k][j]) === 'T')) {
            ++tCount;
          }
        }
        else if (map[k][j] === 'T') ++tCount;
      }

      // 이 부분이 중요. 열을 바꾸면 뒷면의 갯수는 N - tCount가 된다.
      // 굳이 열들에 대해 돌지 않아도 바로 구할 수 있기 때문에 시간 내에 풀 수 있다.
      sum += Math.min(tCount, N - tCount);
    }
    
    if (min > sum) min = sum;
  }
};

go();

console.log(min);