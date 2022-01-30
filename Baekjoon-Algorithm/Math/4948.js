const readline = require('readline');
// const inputs = 
// `1
// 10
// 13
// 100
// 1000
// 10000
// 100000
// 0`.split('\n');
const inputs = [];

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

const getPrimeNumbers = (end) => {
  let primeNumbers = Array(end + 1).fill(true);

  primeNumbers[0] = false;
  primeNumbers[1] = false;

  for (let i = 2; i <= Math.floor(Math.sqrt(end)); ++i) {
    if (primeNumbers[i]) {
      for (let j = i * i; j <= end; j += i) {
        primeNumbers[j] = false;
      }
    }
  }

  return primeNumbers.map((val, idx) => val ? idx : undefined).filter(v => v);
};

const solve = () => {
  const nums = inputs.slice(0, inputs.length - 1).map(e => +e);
  const primeNumbers = getPrimeNumbers(250000);

  for (let i = 0; i < nums.length; ++i) {
    const N = nums[i];
    let cnt = 0;
    for (let j = 0; j < primeNumbers.length; ++j) {
      if (primeNumbers[j] > 2 * N) break;
      if (primeNumbers[j] > N && primeNumbers[j] <= 2 * N) {
        ++cnt;
      }
    }
    console.log(cnt);
  }
};

// solve();
