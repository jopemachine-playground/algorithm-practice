const fs                = require('fs');
// const [N, ...inputs]       = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

// 틀린 이유 : d일 안에 해달라는 강연은 d일 보다 먼저 해줘도 된다.
// 그래서 이 문제는 정렬만으로 풀 수 없고 우선순위 큐를 써야 한다.

// 아래 답은 11이 아니라 20이어야 함. 문제를 잘못 이해함.
// 반례
const [N, ...inputs] = `
3
1 1
10 2
10 2`.trim().split('\n');

const lectures = inputs.map(input => input.split(' ').map(e => +e));

// d를 내림차순으로, d가 같은 경우 p의 내림차순으로 정렬한다.
// 예 : 
// [
//   [ 5, 20 ],
//   [ 50, 10 ],
//   [ 10, 3 ],
//   [ 8, 2 ],
//   [ 100, 2 ],
//   [ 2, 1 ],
//   [ 20, 1 ]
// ]
lectures.sort((a, b) => {
  if (a[1] === b[1]) return a[0] < b[0] ? 1 : -1;
  return a[1] < b[1] ? 1 : -1
});

let day;
let ans = 0;

for (let i = 0; i < lectures.length; ++i) {
  // lectures[i][1]가 day와 같은 경우 이미 최댓값을 더했으므로 패스.
  if (lectures[i][1] === day) continue;
  ans += lectures[i][0];
  day = lectures[i][1];
}

console.log(ans);