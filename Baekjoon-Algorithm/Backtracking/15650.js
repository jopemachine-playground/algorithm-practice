const readline = require('readline');

const inputs = [];

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

const solve = () => {
  const [N, M] = inputs[0].split(' ').map(e => +e);

  const pick = (nums, picked = [], idx = 0, selectedIdx = 0) => {
    let result = [];

    if (selectedIdx >= M) {
      return [[...picked]];
    }

    if (idx >= nums.length) {
      return [];
    }

    // 그 수를 고르는 경우
    picked.push(nums[idx]);
    result = [...result, ...pick(nums, picked, idx + 1, selectedIdx + 1)];
    picked.pop();

    // 그 수를 고르지 않는 경우
    result = [...result, ...pick(nums, picked, idx + 1, selectedIdx)];

    return result;
  };

  let arr = Array(N);
  for (let i = 0; i < N; ++i) {
    arr[i] = i + 1;
  }

  const res = pick(arr);

  console.log(res.map(arr => arr.join(' ')).join('\n'));
};
