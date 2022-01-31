const readline = require('readline');
// const inputs = 
// `3
// 8
// 10
// 16
// 0`.split('\n');
const inputs = [];

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

let isPrimeNumbers;

const getPrimeNumbers = (end) => {
  isPrimeNumbers = Array(end + 1).fill(true);

  isPrimeNumbers[0] = false;
  isPrimeNumbers[1] = false;

  for (let i = 2; i <= Math.floor(Math.sqrt(end)); ++i) {
    if (isPrimeNumbers[i]) {
      for (let j = i * i; j <= end; j += i) {
        isPrimeNumbers[j] = false;
      }
    }
  }

  return isPrimeNumbers.map((val, idx) => val ? idx : undefined).filter(v => v);
};

const solve = () => {
  const T = +inputs[0];
  const nums = inputs.slice(1, T + 1).map(e => +e);
  const primeNumbers = getPrimeNumbers(10000);

  for (let i = 0; i < nums.length; ++i) {
    const N = nums[i];

    let leftValue;
    let rightValue;

    for (let j = 0; j <= primeNumbers.length; ++j) {
      const left = primeNumbers[j];
      const right = N - left;
      // rightValue가 소수가 아닌 경우 패스하면 자동으로 두 소수의 합이 잡힘
      if (!isPrimeNumbers[right]) continue;

      // left가 커지는 순간 볼 필요 (중복) X
      if (left > right) break;

      if (!leftValue || (rightValue - leftValue > right - left)) {
        leftValue = left;
        rightValue = right;
      }

      if (leftValue >= N) break;
    }

    console.log(`${leftValue} ${rightValue}`);
  }
};

// solve();
