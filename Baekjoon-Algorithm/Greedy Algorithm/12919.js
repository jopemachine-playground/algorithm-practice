const fs      = require('fs');
const [S, T]  = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [S, T]    = `
// A
// ABBA
// `.trim().split("\n");

// 매번 문자열이 A가올지 B가 올지 결정하려면 2^(T-S)이 되지만,
// 아래처럼 풀면 모든 단계에서 문자열의 길이가 1씩 줄어듬을 보장할 수 있기 때문에,
// (T-S)^2이 된다. 이 때 reverse 함수 호출 때문에, 총 시간복잡도는 (T-S)^3이 된다.
// BFS로 구현했지만, 재귀로 구현해도 된다.
const possible = () => {
  const que = [];
  que.push(T);

  while (que.length > 0) {
    const cT = que.shift();
    if (cT === S) return true;

    if (cT.length < S.length) continue;
    if (cT.startsWith('A') && cT.endsWith('B')) continue;

    // 두 번씩 푸시하니까 2^N 처럼 보이지만 그렇지 않음에 주의할 것.
    if (cT.endsWith('A')) {
      que.push(cT.slice(0, cT.length - 1));
    }
  
    if (cT.startsWith('B')) {
      que.push(cT.slice(1, cT.length).split('').reverse().join(''));
    }
  }
};

console.log(possible() ? 1 : 0);