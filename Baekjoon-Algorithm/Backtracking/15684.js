const fs                  = require('fs');
// const [first, ...lines]   = `
// 5 6 6
// 1 1
// 3 1
// 5 2
// 4 3
// 2 3
// 1 4`
//                             .trim()
//                             .split('\n');
const [first, ...lines]   = fs.readFileSync("/dev/stdin")
                            .toString()
                            .trim()
                            .split('\n');

const [N, M, H] = first.split(' ').map(e => +e);

// j에 값이 있다면 h 높이에서 주어진 j => j + 1로 이동
// row => h, col => j
const movePos = Array.from(Array(H), () => Array(N - 1).fill(false));

// 이차원 배열 인풋 받을 때 모든 인풋은 무조건 row, col으로 받고 row, col이 의미하는 바는 주석으로 써 놓자.
// 안 그럼 헷갈림...
for (const line of lines) {
  const [row, col] = line.split(' ').map(e => +e);
  movePos[row - 1][col - 1] = true;
}

// 모든 i번 점이 i번으로 돌아 오는지 체크한다.
const possible = () => {
  for (let i = 0; i < N - 1; ++i) {
    let start = i;
    let height = 0;

    for (; height < H; ++height) {
      // 오른쪽으로 이동
      if (movePos[height][start]) {
        start = start + 1;
      }
      // 왼쪽으로 이동
      else if (start - 1 >= 0 && movePos[height][start - 1]) {
        start = start - 1;
      }
    }

    if (start !== i) return false;
  }

  return true;
};

const goNext = (src, height, pickedCnt) => {
  // 모두 다 본 경우
  if (src === N - 1 && height === H - 1) {
    return;
  }
  // 이번 세로선에서의 마지막 후보인 경우
  else if (height === H - 1) {
    go (src + 1, 0, pickedCnt);
    return;
  }
  // 다음 후보
  else {
    go (src, height + 1, pickedCnt);
    return;
  }
}

let min = Infinity;

const printMap = () => {
  console.log('----------------------------------------')
  // Row
  for (let i = 0; i < H; ++i) {
    // Col
    for (let j = 0; j < N - 1; ++j) {
      process.stdout.write((movePos[i][j] ? 1 : 0) + ' ');
    }
    console.log();
  }
}

// 3개를 고를 때 까지 백트랙킹
const go = (src, height, pickedCnt = 0) => {
  // printMap();

  if (possible()) {
    min = Math.min(min, pickedCnt);
  }

  // 최대 3개 까지 골라본다.
  if (pickedCnt === 3) {
    return;
  }

  // 이미 있는 경우 다음으로
  if (movePos[height][src]) {
    goNext(src, height, pickedCnt);
    return;
  }

  // 두 가로선이 연속할 수 없기 때문에, 이 경우에도 그냥 다음으로 넘어가면 됨.
  if (
    (src - 1 >= 0 && movePos[height][src - 1]) ||
    (src + 1 < N && movePos[height][src + 1])
  ) {
    goNext(src, height, pickedCnt);
    return;
  }

  // 없는 경우 여기에 놔 보고 백트랙킹
  movePos[height][src] = true;
  goNext(src, height, pickedCnt + 1);
  movePos[height][src] = false;
  goNext(src, height, pickedCnt);
};

go (0, 0);

console.log(min === Infinity ? -1 : min);