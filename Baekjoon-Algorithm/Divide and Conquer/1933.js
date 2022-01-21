const fs = require('fs');
const [n, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// const [n, ...inputs] = `
// 8
// 1 11 5
// 2 6 7
// 3 13 9
// 12 7 16
// 14 3 25
// 19 18 22
// 23 13 29
// 24 4 28
// `.trim().split("\n");

const N = +n;

// x1 좌표를 기준으로 정렬
const datas = inputs.map(input => {
  const [x1, h, x2] = input.split(' ').map(e => +e);
  return { x1, x2, h };
}).sort((item1, item2) => item1.x1 > item2.x1 ? 1 : -1);

// 두 스카이라인을 병합.
// mergeSort의 merge와 비슷한 전략 (투 포인터)으로 작동한다.
// left, right는 빌딩의 각 x,h를 나타내는 점들의 배열, left[i], right[j]는 스카이라인의 각 점들.
const merge = (left, right) => {
  // 두 스카이 라인의 인덱스를 투 포인터로 유지.
  let i = 0; j = 0;
  // 두 스카이 라인의 높이를 투 포인터로 유지.
  let h1 = 0; h2 = 0;

  // 병합된 스카이라인 결과
  const result = [];
  while (i < left.length && j < right.length) {
    const u = left[i];
    const v = right[j];
    // x, h는 이번에 갱신될 점의 x 좌표 및 높이
    let x, h;

    if (u.x >= v.x) {
      x = v.x;
      h2 = v.h;
      h = Math.max(h1, h2);
      j++;
    } else {
      x = u.x;
      h1 = u.h;
      h = Math.max(h1, h2);
      i++;
    }

    if (result.length > 0) {
      if (h === result[result.length - 1].h) {
        continue;
      }
      if (x === result[result.length - 1].x) {
        result[result.length - 1].h = h;
        continue;
      }
    }
    result.push({ x, h });
  }

  // 남은 점들이 있다면 모두 추가
  while (i < left.length) {
    result.push(left[i]);
    i++;
  }

  while (j < right.length) {
    result.push(right[j]);
    j++;
  }

  return result;
};

const go = (startIdx = 0, endIdx = datas.length - 1) => {
  if (startIdx === endIdx) {
    return [
      { x: datas[startIdx].x1, h: datas[startIdx].h },
      { x: datas[startIdx].x2, h : 0 },
    ];
  }

  const mid = Math.floor((startIdx + endIdx) / 2);

  const left = go(startIdx, mid);
  const right = go(mid + 1, endIdx);
  return merge(left, right);
};

const res = go();

res.forEach(({ x, h }) => {
  process.stdout.write(`${x} ${h} `);
})