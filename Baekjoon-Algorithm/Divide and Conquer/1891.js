const fs = require('fs');
const [first, second] = fs.readFileSync("/dev/stdin").toString().trim().split('\n');
// const [first, second] = `
// 10 1234123412
// 10 10
// `.trim().split('\n');

const [d, src] = first.split(' ');
const [x, y] = second.split(' ');

// 배열에 분할 정복으로 모든 값을 순회하면 d가 50까지 커지기 때문에 공간복잡도가 2^50 * 2^50이 된다. 그렇게는 풀 수 없음.
// 주어진 사분면 숫자로 위치 (좌표)를 찾고, 새 위치를 계산한 후 다시 해당 숫자로 사분면을 찾는 방식으로 풀면 풀린다.
const findPos = (str = src, unit = Math.pow(2, src.length)) => {
  let x = 0, y = 0;
  let currUnit = unit;
  while (str.length > 0) {
    const ch = str.at(0);
    currUnit = Math.floor(currUnit / 2);
    str = str.slice(1);

    if (ch == '1') {
      x += currUnit;
      y += currUnit;
    } else if (ch == '2') {
      y += currUnit;
    } else if (ch == '3') {
      // 증가 X
    } else if (ch == '4') {
      x += currUnit;
    }
  }

  return {
    x, y
  };
};

const pos = findPos();

const nx = Number(pos.x) + Number(x);
const ny = Number(pos.y) + Number(y);

const findNext = (x = 0, y = 0, unit = Math.pow(2, src.length)) => {
  const currUnit = Math.floor(unit / 2);
  let result = '';

  if (
    x + unit > nx && x <= nx &&
    y + unit > ny && y <= ny
  ) {

    // hack
    let currArea = ' ', k = '';

    if (!k) {
      k = findNext(x + currUnit, y + currUnit, currUnit);
      if (k) currArea = '1';
    }

    if (!k) {
      k = findNext(x, y + currUnit, currUnit);
      if (k) currArea = '2';
    }

    if (!k) {
      k = findNext(x, y, currUnit);
      if (k) currArea = '3';
    }

    if (!k) {
      k = findNext(x + currUnit, y, currUnit);
      if (k) currArea = '4';
    }

    result = currArea + k;

  } else {
    return '';
  }

  return result;
};

const result = findNext();
console.log(result === '' ? -1 : result.trim());