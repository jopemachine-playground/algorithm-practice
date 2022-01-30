// 백준 알고리즘 강의 중급
const fs = require('fs');

const [first, second] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
const [N, S] = first.split(' ').map(e => +e);
const nums = second.split(' ').map(e => +e);

const mid = Math.floor(nums.length / 2);

// 2개의 배열로 나누고 각각 최대 2^20 시간복잡도로 순회하자.
// 그럼, 투 포인터 전략으로 O(N)에 합칠 수 있기 때문에 시간 초과를 피할 수 있게 된다.
const nums1 = nums.slice(0, mid);
const nums2 = nums.slice(mid);

const getSubSeq = (nums) => {
  // 각각의 부분수열들의 합을 저장할 배열
  let sumSubSeq = Array(1 << nums.length).fill(0);

  // 이 때, 해당 부분 수열에서 안 고르는 경우도 있기 때문에 둘 다 0을 포함해줘야 한다.
  for (let i = 0; i < (1 << nums.length); ++i) {
    for (let j = 0; j < nums.length; ++j) {
      // j 번째 수를 포함하는 경우, i번째 합에 더한다.
      if (i & (1 << j)) {
        sumSubSeq[i] += nums[j];
      }
    }
  }

  return sumSubSeq;
};

const subseq1 = getSubSeq(nums1);
const subseq2 = getSubSeq(nums2);

// 하나는 왼쪽에서, 하나는 오른쪽에서 투 포인터 전략으로 합쳐주자
// => 하나는 오름차순으로, 하나는 내림차순으로 정렬해 합치면 좀 더 쉽게 구현할 수 있다.
subseq1.sort((a, b) => a - b);
subseq2.sort((a, b) => b - a);

let idx1 = 0;
let idx2 = 0;

let cnt = 0;

while (idx1 < subseq1.length && idx2 < subseq2.length) {
  const sum = subseq1[idx1] + subseq2[idx2];

  // 아랫 부분의 반복문은 필요 없을 것 같지만 꼭 필요하다
  // sum과 S가 같을 때 idx1, idx2 둘 중 하나는 증가해야 하는데,
  // 한 쪽만 증가하면 수가 중복될 때 경우의 수를 모두 카운트할 수가 없게 된다.
  // 그렇다고 둘 다 증가시켜도 적절하게 카운트 할 수 없다
  // 따라서 앞 숫자와 같은 숫자가 있는 경우 반복문 돌려가면서 각 중복되는 숫자의 개수를 세서 
  // 두 경우의 수를 서로 곱해준 후 더하는 방식으로 세야한다
  if (sum === S) {
    let c1 = 1;
    let c2 = 1;

    ++idx1;
    ++idx2;

    while (idx1 < subseq1.length && subseq1[idx1] === subseq1[idx1 - 1]) {
      ++c1;
      ++idx1;
    }
    while (idx2 < subseq2.length && subseq2[idx2] === subseq2[idx2 - 1]) {
      ++c2;
      ++idx2;
    }

    cnt += c1 * c2;
  } else if (sum > S) {
    ++idx2;
  } else {
    ++idx1;
  }
}

// S가 0일 땐 두 부분수열에서 모두 0이 선택된 경우의 수, 하나를 빼 줘야 한다.
// (크기가 양수인 부분수열만 세야한다!)
// S가 0이 아닌 경우 이 경우는 선택되지 않으므로 상관 없다.
if (S === 0) --cnt;

console.log(cnt);