// Ref: 백준 알고리즘 강의 중급
const fs        = require('fs');
const [N, K]    = fs.readFileSync("/dev/stdin").toString().trim().split(" ").map(e => +e);
// const [N, K]    = `10 12`.trim().split(" ").map(e => +e);

for (let i = 0; i <= N; ++i) {
  const A_Cnt = i;
  const B_Cnt = N - i;
  // A의 갯수 * B의 갯수의 최댓값은 K다. 그렇지 않은 경우는 탐색 공간에서 제외해야 한다.
  if (A_Cnt * B_Cnt < K) continue;

  // B들 사이에 끼어 있는 A의 갯수.
  const cnt = Array.from(Array(B_Cnt + 1), () => 0);

  let remaining = K;

  // 반복문을 돌면서 최대한 높은 인덱스에 하나씩 A를 넣는다. (그리디 알고리즘)
  for (let j = 0; j < A_Cnt; ++j) {
    // 가능한 높은 인덱스에 A를 넣을 것임.
    const whereIsA = Math.min(B_Cnt, remaining);
    cnt[whereIsA]++;
    remaining -= whereIsA;
  }

  for (let j = B_Cnt; j >= 0; --j) {
    for (let k = 0; k < cnt[j]; ++k) {
      process.stdout.write('A');
    }

    if (j > 0) {
      process.stdout.write('B');
    }
  }

  process.exit(0);
}

console.log(-1);