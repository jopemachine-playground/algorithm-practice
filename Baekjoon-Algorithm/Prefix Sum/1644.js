const fs = require('fs');
// const N = +(`3`.toString().trim());
const N = +(fs.readFileSync("/dev/stdin").toString().trim());

const getPrimeNumbers = () => {
  const isPrimeNumbers = Array(N + 1).fill(true);
  isPrimeNumbers[0] = false;
  isPrimeNumbers[1] = false;

  // 마지막까지 남은 수를 소수로 판정한다.
  for (let i = 2; i <= Math.sqrt(N); ++i) {
    // 어떤 수가 지워지지 않았다면 
    if (isPrimeNumbers[i]) {
      // j => 합성된 수. 합성한 수 들을 false로 표기.
      for (let j = i * i; j <= N; j += i) {
        isPrimeNumbers[j] = false;
      }
    }
  }

  return isPrimeNumbers.map((valid, idx) => {
    if (valid) {
      return idx;
    }
    return false;
  }).filter(val => val !== false);
};

const primeNumbers = getPrimeNumbers();

const getPartialSums = (nums) => {
  let result = Array(nums.length);
  result[0] = nums[0];

  for (let i = 1; i < result.length; ++i) {
    result[i] = result[i - 1] + nums[i];
  }

  return result;
};

const primeNumberPartialSums = getPartialSums(primeNumbers);

const getPrefixSum = (left, right) => {
  if (left === 0) return primeNumberPartialSums[right];
  return primeNumberPartialSums[right] - primeNumberPartialSums[left - 1];
};

let left = 0;
let right = 0;
let cnt = 0;

while (right < N) {
  const sum = getPrefixSum(left, right);
  if (sum === N) {
    ++cnt;
    ++right;
  } else if (sum > N) {
    ++left;
  } else {
    ++right;
  }
}

console.log(cnt);