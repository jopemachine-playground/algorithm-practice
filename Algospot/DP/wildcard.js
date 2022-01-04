// Ref: 종만북 8장
const inputs = [];
const readline = require('readline');

// const inputs = [
//   '2',
//   'he?p',
//   '3',
//   'help',
//   'heap',
//   'helpp',
//   '*p*',
//   '3',
//   'help',
//   'papa',
//   'hello',
// ];

readline
  .createInterface(process.stdin, {})
  .on('line', function(line) {
    inputs.push(line.trim());
  }).on('close', function() {
    solve();
  });

class Matcher {
  pattern;
  str;
  cache;

  constructor (pattern, str) {
    this.pattern = pattern;
    this.str = str;
    this.cache = [];

    for (let i = 0; i <= this.pattern.length; ++i) {
      this.cache[i] = [];
    }
  }

  getMatch(patternIdx = 0, strIdx = 0) {
    if (this.cache[patternIdx][strIdx]) {
      return this.cache[patternIdx][strIdx];
    }

    while (
      patternIdx < this.pattern.length &&
      strIdx < this.str.length &&
      ((this.pattern[patternIdx] === this.str[strIdx]) || this.pattern[patternIdx] === '?')
    ) {
      ++patternIdx;
      ++strIdx;
    }

    // 문자열이 매치 되지 않았는데 pattern이 끝났다.
    if (patternIdx === this.pattern.length) {
      const ret = this.str.length === strIdx ? 1 : -1;
      this.cache[patternIdx][strIdx] = ret;
      return ret;
    }

    // pattern이 아직 끝나지 않았는데 *가 나왔다 => 
    if (this.pattern[patternIdx] === '*') {
      for (let skip = 0; skip + strIdx <= this.str.length; ++skip) {
        if (this.getMatch(patternIdx + 1, strIdx + skip) === 1) {
          this.cache[patternIdx][strIdx] = 1;
          return 1;
        }
      }
    }

    return -1;
  }
}

const solve = () => {
  const tc = inputs[0];

  for (let i = 1; i < inputs.length;) {
    const W = inputs[i];
    const N = Number(inputs[i + 1]);
    const strs = inputs.slice(i + 2, i + N + 2);

    const ret = [];
    for (const str of strs) {
      const match = new Matcher(W, str).getMatch();
      if (match === 1) ret.push(str);
    }

    console.log(ret.sort().join('\n'));

    i += N + 2;
  }
};

solve();