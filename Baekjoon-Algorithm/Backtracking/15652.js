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

  let ans = [];
  
  const pick = (picked = [], idx = 0, prevIdx = 0) => {
    let result = [];
    if (idx === M) {
      ans.push([...picked]);
      return;
    }
  
    for (let i = prevIdx; i < N; ++i) {
      picked.push(i + 1);
      pick(picked, idx + 1, i);
      picked.pop();
    }
  
    return result;
  };

  pick();
  console.log(ans.map(str => str.join(' ')).join('\n'));
};
