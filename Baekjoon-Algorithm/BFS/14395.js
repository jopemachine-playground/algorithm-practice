const fs        = require('fs');
const [s, t]    = fs.readFileSync("/dev/stdin").toString().trim().split(' ').map(e => +e);
// const [s, t]    = `7 392`.trim().split(' ').map(e => +e);

// 어떤 값에서 연산되었는지 이전의 값을 기록.
const from = [];
// 해당 값이 어떤 연산자로 연산되었는지 기록.
const oprs = [];

const print = (val = s, dst = t) => {
  if (val === dst) return '';
  // dst가 어떤 값에서 연산되었는지 거슬러 올라가며 연산에 사용된 연산자들을 문자열에 더함.
  return print(s, from[dst]) + oprs[dst];
};

const go = () => {
  const que = [];
  const visited = [];
  que.push({
    val: s,
    opr: '',
  });

  while(que.length > 0) {
    const { val } = que.shift();

    if (val === t) {
      return print();
    }

    const cands = [
      {
        opr: '*',
        val : val * val,
      },
      {
        opr: '+',
        // val << 1 넣으면 32 비트 넘을 때 오버플로우 나기 때문에 틀림에 주의.
        val : val * 2,
      },
      {
        opr: '-',
        val: 0,
      },
      {
        opr: '/',
        val: val === 0 ? undefined : 1
      }
    ];

    for (const cand of cands) {
      if (!cand.val || visited[cand.val]) continue;
      from[cand.val] = val;
      oprs[cand.val] = cand.opr;

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
