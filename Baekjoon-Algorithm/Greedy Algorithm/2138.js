// Ref: 백준 알고리즘 강의 중급
const fs                = require('fs');
const [N, src, dst]     = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [N, src, dst] = `
// 3
// 0000
// 0000
// `.trim().split('\n');

let srcArr               = src.split('').map(e => +e);
const dstArr             = dst.split('').map(e => +e);

const pressSwitch = (idx) => {
  if (idx >= N) throw new Error('Range error');
  for (let i = idx - 1; i <= idx + 1; ++i) {
    if (i >= 0 && i < N) {
      srcArr[i] = 1 - srcArr[i];
    }
  }
};

let min = -1;
let ans = -1;

const go = (firstOn) => {
  ans = -1;
  srcArr = src.split('').map(e => +e);
  firstOn && pressSwitch(0);
  // firstOn && console.log('0번째 스위치를 켭니다.')
  // !firstOn && console.log('0번째 스위치를 끕니다.')

  for (let i = 0; i < N - 1; ++i) {
    // i 번째 값이 같다면 i + 1 번째 스위치를 누르지 않고, 다른 경우에 누른다.
    if (srcArr[i] !== dstArr[i]) {
      // console.log(`${i + 1}번째 스위치를 켭니다`);
      pressSwitch(i + 1);
      ans = ans === -1 ? (firstOn ? 2 : 1) : ans + 1;
    } else {
      // console.log(`${i + 1}번째 스위치를 끕니다`);
    }
  }

  if (srcArr.join('') === dstArr.join('')) {
    // ans이 나오지 않은 경우 무시 
    if (ans !== -1) {
      if (min !== -1) {
        min = Math.min(ans, min);
      } else {
        min = ans;
      }
    }
  }
};

if (src === dst) {
  console.log(0);
  process.exit(0);
}

// 첫 번째 스위치를 켜는 경우
go(true);
// 첫 번째 스위치를 끄는 경우
go(false);

console.log(min);