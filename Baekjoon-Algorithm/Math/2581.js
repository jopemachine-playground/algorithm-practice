const readline = require('readline');
// const inputs = ['64', '65'];
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
  const [N, M] = inputs.map(e => +e);
  const primeNumbers = getPrimeNumbers(10000);
  let min = Infinity;
  let sum = 0;
  for (let i = 0; i <= 10000; ++i) {
    if (primeNumbers[i] >= N && primeNumbers[i] <= M) {
      if (min === Infinity) {
        min = primeNumbers[i];
      }
      sum += primeNumbers[i];
    }
  }

  if (min === Infinity) {
    console.log(-1);
  } else {
    console.log(sum);
    console.log(min);
  }
};

// solve();
