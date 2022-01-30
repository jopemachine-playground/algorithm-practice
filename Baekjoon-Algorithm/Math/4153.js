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
  const seqs = inputs.slice(0, inputs.length - 1);
  for (const seq of seqs) {
    const [a, b, c] = seq.split(' ').map(e => +e).sort((a, b) => a - b);
    if (a * a + b * b === c * c) {
      console.log('right');
    } else {
      console.log('wrong');
    }
  }
};

// solve();
