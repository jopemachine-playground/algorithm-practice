
const fs = require('fs');
// const [t, n, first, m, second] = `
// 5
// 4
// 1 3 1 2
// 3
// 1 3 2`.trim().split("\n");
const [t, n, first, m, second] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const T = +t;
const N = +n;
const M = +m;

const nums1 = first.split(' ').map(e => +e);
const nums2 = second.split(' ').map(e => +e);

const getPartialSums = (nums) => {
  let sums = [nums[0]];
  for (let i = 1; i < nums.length; ++i) {
    sums[i] = sums[i - 1] + nums[i];
  }
  return sums;
};

const partialSums1 = getPartialSums(nums1);
const partialSums2 = getPartialSums(nums2);

const getPrefixSum = (partialSums, left, right) => {
  if (left === 0) return partialSums[right];
  return partialSums[right] - partialSums[left - 1];
};

const getAllPrefixSums = (partialSums) => {
  let allPrefixSums = [];
  for (let i = 0; i < partialSums.length; ++i) {
    for (let j = i; j < partialSums.length; ++j) {
      const prefixSums = getPrefixSum(partialSums, i, j);
      allPrefixSums.push(prefixSums);
    }
  }
  return allPrefixSums;
};

const seq1 = getAllPrefixSums(partialSums1);
const seq2 = getAllPrefixSums(partialSums2);

seq1.sort((a, b) => a - b);
seq2.sort((a, b) => b - a);

let i = 0, j = 0;

let cnt = 0;
while (i < seq1.length && j < seq2.length) {
  const sum = seq1[i] + seq2[j];
  if (sum === T) {
    let c1 = 1, c2 = 1;

    ++i;
    ++j;

    while (i < seq1.length && seq1[i] === seq1[i - 1]) {
      ++c1;
      ++i;
    }

    while (j < seq2.length && seq2[j] === seq2[j - 1]) {
      ++c2;
      ++j;
    }

    cnt += c1 * c2;
  }
  else if (sum > T) {
    ++j;
  }
  else {
    ++i;
  }
}

console.log(cnt);