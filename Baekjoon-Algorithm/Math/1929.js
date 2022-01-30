const readline = require('readline');
// const inputs = ['3', '16'];
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
  const [M, N] = inputs[0].split(' ').map(e => +e);
  const primeNumbers = getPrimeNumbers(1000000);
  let res = [];

  for (let i = 0; i <= 1000000; ++i) {
    if (primeNumbers[i] >= M && primeNumbers[i] <= N) {
      res.push(primeNumbers[i]);
    }
  }

  console.log(res.join('\n'));
};

// solve();
