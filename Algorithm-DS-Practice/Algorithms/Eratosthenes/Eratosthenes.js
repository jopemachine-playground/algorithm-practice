// Ref: 종만북
const getPrimeNumbersMap = (until) => {
  const isPrimes = [];

  for (let i = 0; i < until; ++i) {
    isPrimes[i] = true;
  }

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

const getPrimeNumbersArr = (until) => {
  return getPrimeNumbersMap(until).map((val, idx) => val ? idx : undefined).filter(v => v);
};

console.log(getPrimeNumbersArr(1000));
