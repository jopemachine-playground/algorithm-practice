const fs = require('fs');
const [ax, ay, az, bx, by, bz, cx, cy, cz] = fs.readFileSync("/dev/stdin").toString().trim().split(" ").map(e => +e);
// const [ax, ay, az, bx, by, bz, cx, cy, cz] = `0 0 0 1 1 1 7 6 5`.trim().split(" ").map(e => +e);

const getDist = (x1, y1, z1, x2, y2, z2) => {
  return Math.sqrt(
    Math.pow(x1 - x2, 2) +
    Math.pow(y1 - y2, 2) +
    Math.pow(z1 - z2, 2)
  );
};

let left = 0;
let right = 1;

const dx = bx - ax;
const dy = by - ay;
const dz = bz - az;

// 삼분 탐색은 구간을 세 개로 쪼개지만, 투 포인터 전략인 것은 똑같다.
// 이분 탐색은 함수가 단조 증가 / 단조 감소 할 때만 사용 가능하지만,
// 삼분 탐색은 볼록 함수에서 극값을 찾을 때 사용 가능하다.
while (Math.abs(right - left) >= 1e-9) {
  let m1 = (2 * left + right) / 3;
  let m2 = (left + 2 * right) / 3;

  const d1 = getDist(
    ax + m1 * dx,
    ay + m1 * dy,
    az + m1 * dz,
    cx,
    cy,
    cz,
  );

  const d2 = getDist(
    ax + m2 * dx,
    ay + m2 * dy,
    az + m2 * dz,
    cx,
    cy,
    cz,
  );

  if (d1 > d2) {
    left = m1;
  } else {
    right = m2;
  }
}

const m = (left + right) / 2;

console.log(
  getDist(
    ax + m * dx,
    ay + m * dy,
    az + m * dz,
    cx, cy, cz)
  .toFixed(10)
);