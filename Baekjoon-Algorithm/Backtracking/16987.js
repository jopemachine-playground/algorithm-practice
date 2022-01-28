const fs                = require('fs');
// const [n, ...inputs]    = `
// 3
// 213 295
// 153 24
// 15 233`
//       .trim()
//       .split('\n')
//       .map((str) => str.split(' ').map(str => Number(str)));

const [n, ...inputs]    = fs.readFileSync("/dev/stdin")
      .toString()
      .trim()
      .split('\n')
      .map((str) => str.split(' ').map(str => Number(str)));

const N = n[0];

const eggInfos = inputs.map(([hp, weight]) => {
  return {
    hp,
    weight, 
  }
});

const getBrokenCnt = () => {
  return eggInfos.filter(info => info.hp <= 0).length;
};

let max = 0;

// idx는 던지는 계란의 인덱스,
const go = (idx) => {
  if (idx === N) {
    max = Math.max(max, getBrokenCnt());
    return;
  }

  // 손에 든 계란이 깨져 있을 때:: 보다 쉬운 예외 처리를 하게 해 준다.
  // go 위 아래로 분기 나누는 것 보다 깔끔하고 쉽게 예외 처리 할 수 있음.
  if (eggInfos[idx].hp <= 0) {
    return go (idx + 1);
  }

  let ok = true;
  // i는 맞는 계란의 인덱스
  for (let i = 0; i < N; ++i) {
    if (i === idx) continue;
    if (eggInfos[i].hp > 0) {
      ok = false;

      eggInfos[i].hp -= eggInfos[idx].weight;
      eggInfos[idx].hp -= eggInfos[i].weight;
  
      go (idx + 1);
  
      eggInfos[i].hp += eggInfos[idx].weight;
      eggInfos[idx].hp += eggInfos[i].weight;
    }
  }

  // 이 부분이 중요!
  // 깨지지 않은 다른 계란이 없을 때의 예외 처리.
  if (ok) {
    max = Math.max(max, getBrokenCnt());
  }
};

// 가장 처음에 던져야 하는 계란은 가장 왼쪽의 계란.
go(0);

console.log(max);