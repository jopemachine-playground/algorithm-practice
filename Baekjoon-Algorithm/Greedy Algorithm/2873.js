const fs                    = require('fs');
// const [first, ...inputs]    = `
// 3 4
// 1 2 1 1
// 1 1 0 1
// 1 1 1 1`
//                       .trim()
//                       .split('\n');
const [first, ...inputs]    = fs.readFileSync("/dev/stdin")
                      .toString()
                      .trim()
                      .split('\n');

const map = inputs.map(input => input.split(' ').map(e => +e));

const [R, C] = first.split(' ').map(e => +e);

let result = '';

const findMinPos = () => {
  let min = Infinity;
  let r, c;
  for (let i = 0; i < R; ++i) {
    for (let j = 0; j < C; ++j) {
      // 시작점은 i + j 가 짝수 (0) 이다. 그럼 i + j 가 홀수인 점들 중에서
      // 최소점을 골라 방문하지 않는다면 만들 수 있는 최댓값을 만들게 된다.
      // (체스판 생각해 볼 것)
      if ((i + j) % 2 === 1 && min > map[i][j]) {
        min = map[i][j];
        r = i;
        c = j;
      }
    }
  }

  return { r, c };
}

// C이 짝수이고 R가 홀수, 또는 둘 다 홀수
if (R % 2 === 1) {
  let rowIdx = 0;

  for (let i = 0; i < R; ++i) {
    if (rowIdx % 2 === 0) {
      result += 'R'.repeat(C - 1);
    }
    else {
      result += 'L'.repeat(C - 1);
    }

    if (rowIdx !== R - 1) {
      result += 'D';
    }

    ++rowIdx;
  }
}
// C가 홀수 이고, R이 짝수 
else if (C % 2 === 1) {
  let colIdx = 0;

  for (let i = 0; i < C; ++i) {
    if (colIdx % 2 === 0) {
      result += 'D'.repeat(R - 1);
    }
    else {
      result += 'U'.repeat(R - 1);
    }

    if (colIdx !== C - 1) {
      result += 'R';
    }

    ++colIdx;
  }
} 
// 둘 다 짝수
else {
  // 피해갈 값을 하나 정함
  const { r, c } = findMinPos();

  let startResult = '', endResult = '';
  let rowStartIdx = 0, rowEndIdx = R - 1;

  // 위 아래에서 자름
  while (rowStartIdx + 2 <= r || rowEndIdx - 2 >= r) {
    // 앞에서 두 줄 자른다.
    if (rowStartIdx + 2 <= r) {
      startResult += 'R'.repeat(C - 1) + 'D' + 'L'.repeat(C - 1) + 'D';
      rowStartIdx += 2;
    }
    // 뒤에서 두 줄 자른다.
    if (rowEndIdx - 2 >= r) {
      endResult = 'D' + 'L'.repeat(C - 1) + 'D' + 'R'.repeat(C - 1) + endResult;
      rowEndIdx -= 2;
    }
  }

  // 왼쪽 오른쪽에서 자름

  let colStartIdx = 0, colEndIdx = C - 1;
  while (colStartIdx + 2 <= c || colEndIdx - 2 >= c) {
    // 왼쪽에서 두 줄 자른다.
    if (colStartIdx + 2 <= c) {
      startResult += 'DRUR';
      colStartIdx += 2;
    }
    // 오른쪽에서 두 줄 자른다.
    if (colEndIdx - 2 >= c) {
      endResult = 'RURD' + endResult;
      colEndIdx -= 2;
    }
  }

  // 마지막 결과는 항상 2*2 배열이므로.. 둘 중 하나다.
  if (map[rowStartIdx][colStartIdx + 1] > map[rowStartIdx + 1][colStartIdx]) {
    startResult += 'RD';
  } else {
    startResult += 'DR';
  }

  result = startResult + endResult;
}

console.log(result);