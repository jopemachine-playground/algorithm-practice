const readline = require('readline');
const inputs = [];
// const inputs = `100 99 1000000000`.trim().split('\n');

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

const solve = () => {
  const [A, B, V] = inputs[0].split(' ').map(e => +e);
  // 하루애 몇 미터 올라가는지
  const per = A - B;
  // 마지막 값만 빼고 며칠 걸리는 지 계산
  const pairCnt = Math.ceil((V - A) / per);
  // 마지막 값 낮을 더해 줌
  console.log(pairCnt + 1);
};

// solve();