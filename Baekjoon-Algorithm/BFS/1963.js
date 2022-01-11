const fs                  = require('fs');
// const [T, ...lines]   = fs.readFileSync("/dev/stdin")
//                             .toString()
//                             .trim()
//                             .split('\n');
const [T, ...lines]   = `
3
1033 8179
1373 8017
1033 1033
`.trim().split('\n');

const nums = lines.map(line => line.split(' ').map(e => +e));

// Ref: 종만북
const getPrimeNumbers = (until) => {
  const isPrimes = [];

  for (let i = 0; i < until; ++i) {
    isPrimes[i] = true;
  }

  // 0, 1은 예외 처리
  [isPrimes[0], isPrimes[1]] = [false, false];

  const sqrtN = Math.floor(Math.sqrt(until));

  for (let i = 2; i <= sqrtN; ++i) {
    if (isPrimes[i]) {
      for (let j = i * i; j <= until; j += i) {
        isPrimes[j] = false;
      }
    }
  }

  return isPrimes;
};

const isPrimes = getPrimeNumbers(10000);

const deltas = [
  [  1,2,3,4,5,6,7,8,9],
  [0,1,2,3,4,5,6,7,8,9],
  [0,1,2,3,4,5,6,7,8,9],
  [0,1,2,3,4,5,6,7,8,9],
];

let isVisited = [];
for (let i = 0; i < 10000; ++i) {
  isVisited[i] = false;
}

const go = (src, dst) => {
  const que = [];
  isVisited = [];

  que.push({
    next: src,
    dist: 0,
  });

  while (que.length > 0) {
    const { next, dist } = que.shift();
    if (next === dst) {
      return dist;
    }

    // deltaIdx번째 자릿 수를..
    for (let deltaIdx = 0; deltaIdx < 4; ++deltaIdx) {
      const cands = deltas[deltaIdx];
      // cand로 바꿔본다.
      for (let i = 0; i < cands.length; ++i) {
        let swapped = String(next);

        // 같은 숫자면 패스
        if (cands[i] == swapped[deltaIdx]) continue;

        swapped = swapped.substring(0, deltaIdx) +
                  String(cands[i]) +
                  swapped.substring(deltaIdx + 1, swapped.length);

        const swapedNumber = Number(swapped);

        // 스왑해봤더니 이전에 계산해봤던 숫자라면 패스
        if (isVisited[swapedNumber]) continue;

        // 바꾼 숫자가 소수인 경우 push
        if (isPrimes[swapedNumber]) {
          que.push({
            next: swapedNumber,
            dist: dist + 1,
          });
        }

        // 소수가 아니여도 어쨌든 방문.
        isVisited[swapedNumber] = true;
      }
    }
  }
};

nums.map((arr) => console.log(go(arr[0], arr[1])));