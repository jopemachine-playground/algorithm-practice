// Ref: 백준 알고리즘 강좌 중급,
// from, how 배열을 만들어 출력함으로써 timeout 제거.
const fs        = require('fs');
const inputs    = fs.readFileSync("/dev/stdin")
                  .toString()
                  .trim()
                  .split('\n')
                  .slice(1)
                  .map((str) => str.split(' ').map(str => Number(str)));

// const inputs = [
//   '1234 3412',
//   '1000 1',
//   '1 16',
// ].map((str) => str.split(' ').map(str => Number(str)));

const from = [];
const how = [];

for (let i = 0; i < 10000; ++i) {
  from[i] = false;
  how[i] = false;
}

const execute_D = (src) => {
  return (src << 1) % 10000;
};

const execute_S = (src) => {
  return src === 0 ? 9999 : src - 1;
};

const execute_L = (src) => {
  const d1 = Math.floor(src / 1000);
  const d234 = (src % 1000) * 10;
  return d234 + d1;
};

const execute_R = (src) => {
  const d4 = (src % 10) * 1000;
  const d123 = Math.floor(src / 10);
  return d4 + d123;
};

// 이 문제에서 배울 것 :: 매번 string 더하기를 하고 있으면 느리니까
// 이런 식으로 from, how 배열에 다 박아놨다가 출력하는 함수를 만들어서 처리하는 방법.
const print = (src, dst) => {
  if (src === dst) return;
  // dst가 어디에서 왔는지 거슬러 올라간다.
  print(src, from[dst]);
  // 맨 아래 쪽 how 부터 출력하기 시작한다.
  process.stdout.write(how[dst]);
};

const solve = (src, dst) => {
  const isTried = [];
  for (let i = 0; i < 10000; ++i) isTried[i] = false;

  const que = [];

  que.push(src);

  while (que.length > 0) {
    const next = que.shift();

    const d = execute_D(next);

    if (!isTried[d]) {
      que.push(d);
      isTried[d] = true;
      from[d] = next;
      how[d] = 'D';
    }

    const s = execute_S(next);

    if (!isTried[s]) {
      que.push(s);
      isTried[s] = true;
      from[s] = next;
      how[s] = 'S';
    }

    const l = execute_L(next);

    if (!isTried[l]) {
      que.push(l);
      isTried[l] = true;
      from[l] = next;
      how[l] = 'L';
    }

    const r = execute_R(next);

    if (!isTried[r]) {
      que.push(execute_R(next));
      isTried[r] = true;
      from[r] = next;
      how[r] = 'R';
    }
  }

  print(src, dst);
};

inputs.forEach((input) => {
  const [A, B] = input;
  solve(A, B);
  console.log();
});
