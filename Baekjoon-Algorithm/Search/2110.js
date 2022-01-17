const fs = require('fs');
const [first, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [first, ...inputs] = `
// 2 2 
// 6
// 5
// `.trim().split("\n");

const [N, C] = first.split(' ').map(e => +e);
const nums = inputs.map(e => +e).sort((a, b) => a - b);

const possibleToPut = (dist) => {
  let cnt = 1;
  let last = nums[0];

  for (let i = 0; i < nums.length; ++i) {
    if (nums[i] - last >= dist) {
      last = nums[i];
      cnt++;
    }
  }

  return cnt >= C;
};

let ans = 1;

let start = 1;
// 공유기의 최대 거리는 어차피 1백만까지 안 해 봐도 된다. 맨 끝 공유기와 맨 처음 공유기의 거리보다는
// 절대 커질 수 없으니까.
let end = nums[nums.length - 1] - nums[0];

while (start <= end) {
  let mid = Math.floor((start + end) / 2);

  if (possibleToPut(mid)) {
    start = mid + 1;
    ans = mid;
  } else {
    end = mid - 1;
  }
}

console.log(ans);