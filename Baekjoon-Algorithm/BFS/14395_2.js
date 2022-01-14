const fs        = require('fs');
const [s, t]    = fs.readFileSync("/dev/stdin").toString().trim().split(' ').map(e => +e);
// const [s, t]    = `7 256`.trim().split(' ').map(e => +e);

const go = () => {
  const que = [];
  const visited = [];
  que.push({
    val: s,
    result: '',
  });

  while(que.length > 0) {
    const { val, result } = que.shift();

    if (val === t) {
      return result;
    }

    const cands = [
      {
        result: result + '*', 
        val : val * val,
      },
      {
        result: result + '+', 
        val : val * 2,
      },
      {
        result: result + '-',
        val: 0,
      },
      {
        result: result + '/',
        val: val === 0 ? undefined : 1
      }
    ];

    for (const cand of cands) {
      if (!cand.val || visited[cand.val]) continue;
      que.push(cand);
      visited[cand.val] = true;
    }
  }

  return -1;
};

if (s === t) {
  console.log(0);
  process.exit(0);
}

console.log(go());