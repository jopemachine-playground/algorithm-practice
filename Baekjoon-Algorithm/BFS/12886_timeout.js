const fs        = require('fs');
const [A, B, C]    = fs.readFileSync("/dev/stdin")
                  .toString()
                  .trim()
                  .split(' ')
                  .map(e => +e);
// const [A, B, C] = `10 15 35`.trim().split(' ').map(e => +e);

const sum = A + B + C;

const visited = [];
// 500개를 한 곳에 다 몰아줬을 때 1500개 이므로 이것보다 더 커질 순 없다. => 1500개
for (let i = 0; i < 1500; ++i) {
  visited[i] = [];
  for (let j = 0; j < 1500; ++j) {
    visited[i][j] = false;
  } 
}

const go = () => {
  const que = [];
  que.push({
    group1: A,
    group2: B,
  });

  visited[A][B] = true;
  visited[B][A] = true;

  while (que.length > 0) {
    const {group1, group2} = que.shift();

    const group3 = sum - group1 - group2;

    if (group1 === group2 && group2 === group3) return true;

    if (group1 !== group2) {
      const ng1 = group1 > group2 ? group1 - group2 : 2 * group1;
      const ng2 = group1 < group2 ? group2 - group1 : 2 * group2;
      if (visited[ng1][ng2]) continue;
      que.push({
        group1: ng1,
        group2: ng2,
      });

      visited[ng1][ng2] = true;
      visited[ng2][ng1] = true;
    }

    if (group1 !== group3) {
      const ng1 = group1 > group3 ? group1 - group3 : 2 * group1;
      const ng2 = group1 < group3 ? group3 - group1 : 2 * group3;
      if (visited[ng1][ng2]) continue;
      que.push({
        group1: ng1,
        group2: ng2,
      });

      visited[ng1][ng2] = true;
      visited[ng2][ng1] = true;
    }

    if (group2 !== group3) {
      const ng1 = group2 > group3 ? group2 - group3 : 2 * group2;
      const ng2 = group2 < group3 ? group3 - group2 : 2 * group3;
      if (visited[ng1][ng2]) continue;
      que.push({
        group1: ng1,
        group2: ng2,
      });

      visited[ng1][ng2] = true;
      visited[ng2][ng1] = true;
    }
  }

  return false;
};

if (sum % 3 !== 0) {
  console.log(0);
} else {
  console.log(go() ? 1 : 0);
}