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
  const N = +inputs[0];
  // const N = 14;

  if (N === 1) {
    console.log('1/1');
    return;
  }

  let front = 1;
  let back = 2;

  let down = true;
  for (let i = 2; i < N; ++i) {
    if (down === true && back === 1) {
      ++front;
      down = false;
      continue;
    }
    if (i !== 2 && down === false && front === 1) {
      ++back;
      down = true;
      continue;
    }

    if (down) {
      ++front;
      --back;
    } else {
      --front;
      ++back;
    }
  }

  console.log(`${front}/${back}`);
};
