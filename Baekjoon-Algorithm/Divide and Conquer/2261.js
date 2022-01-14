const fs = require('fs');
// const [first, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
const [first, ...inputs] = `
3
0 0
0 0
1 1
`.trim().split('\n');

const N = +first;
// x 좌표에 대해 오름차순 정렬해 저장.
const dotInfos = inputs.map(input => input.split(' ').map(e => +e))
  .sort((a, b) => a[0] > b[0] ? 1 : -1)
  .map((dotInfo) => {
    return {
      x: dotInfo[0],
      y: dotInfo[1],
    };
  });

const getDist = (pt1, pt2) => {
  return Math.pow(pt1.x - pt2.x, 2) + Math.pow(pt1.y - pt2.y, 2);
};

const closest = (dots, startIdx = 0, endIdx = dotInfos.length - 1) => {
  // 가운데 중심으로 찾아보자.
  const mid = Math.floor((startIdx + endIdx) / 2);
  // 점의 갯수를 닫힌 구간에서 세는 것이니 +1을 더해줘야 함에 주의
  const diff = endIdx - startIdx + 1;

  if (diff <= 3) {
    if (diff === 3) {
      return Math.min(
        getDist(dots[startIdx], dots[endIdx]),
        getDist(dots[startIdx], dots[startIdx + 1]),
        getDist(dots[startIdx + 1], dots[endIdx]),
      );
    } else if (diff === 2) {
      return getDist(dots[startIdx], dots[endIdx]);
    }
  }

  const left = closest(dots, startIdx, mid);
  const right = closest(dots, mid + 1, endIdx);

  let ans = Math.min(left, right);

  const cands = [];

  for (let i = startIdx; i <= endIdx; ++i) {
    const x = dotInfos[i].x - dotInfos[mid].x;
    if (x * x < ans) {
      cands.push(dotInfos[i]);
    }
  }

  cands.sort((pt1, pt2) => pt1.y - pt2.y > 0 ? 1 : -1);

  // 아래 반복문은 원래 N^2이어야 했지만, y좌표 값 비교를 통한 가지치기로 O(1)이 되어버린다 (최대 6번 비교)
  // 물론 정렬이 N lgN 잡아먹으니 전체 시간복잡도는 분할 할 때 lgN * 각 조각에 대해 N lgN = N lg^2 N이 된다.
  for (let i = 0; i < cands.length - 1; ++i) {
    for (let j = i + 1; j < cands.length; ++j) {
      const y = cands[j].y - cands[i].y;
      if (y * y >= ans) break;

      ans = Math.min(ans, getDist(cands[j], cands[i]));
    }
  }

  return ans;
};

console.log(closest(dotInfos));