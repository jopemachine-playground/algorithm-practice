const fs = require('fs');
// const N = +(fs.readFileSync("/dev/stdin").toString().trim());
const N = 6561;

const map = [];
for (let i = 0; i < N; ++i) {
  map[i] = [];
  for (let j = 0; j < N; ++j) {
    map[i][j] = false;
  }
}

const go = (r = 0, c = 0, unit = N) => {
  const currUnit = Math.floor(unit / 3);

  if (unit === 1) {
    map[r][c] = true;
    return;
  }

  // 9개로 문제를 분할해 그 중 8개를 방문한다.
  for (let i = 0; i < 3; ++i) {
    for (let j = 0; j < 3; ++j) {
      if (i === 1 && j === 1) continue;
      go (r + currUnit * i, c + currUnit * j, currUnit);
    }
  }
};

go();

for (let i = 0; i < N; ++i) {
  for (let j = 0; j < N; ++j) {
    process.stdout.write(map[i][j] ? '*' : ' ');
  }
  console.log();
}
