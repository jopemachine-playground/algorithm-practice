const fs                  = require('fs');
// const [first, ...lines]   = `
// 5 5
// #####
// #O..#
// #R..#
// #B..#
// #####`
//                             .trim()
//                             .split('\n')
const [first, ...lines]   = fs.readFileSync("/dev/stdin")
                            .toString()
                            .trim()
                            .split('\n')

// 기울일 수 있는 방향
const deltas = [
  { r: 1, c: 0 },
  { r: 0, c: 1 },
  { r: -1, c: 0 },
  { r: 0, c: -1 },
];

const [N, M] = first.split(' ').map(e => +e);

const map = Array.from(Array(N), () => Array(M).fill('.'));

const findAndInit = () => {
  let R, B, H;
  for (let j = 0; j < lines.length; ++j) {
    const line = lines[j];
    for (let i = 0; i < line.length; ++i) {
      if (line[i] === 'R') {
        R = { r: j, c: i };
      }
      else if (line[i] === 'B') {
        B = { r: j, c: i };
      }
      else if (line[i] === 'O') {
        H = { r: j, c: i };
        // map의 구현 편의 상 .으로 대체
        map[j][i] = '.';
        continue;
      }

      map[j][i] = line[i];
    }
  }

  return {
    R, B, H
  };
}

const {R, B, H} = findAndInit();

const movable = (r, c) => {
  return r >= 0 && c >= 0 && r < N && c < M && map[r][c] !== '#';
};

// map 값은 중요하지 않음. (map의 구현 편의 상 .으로 대체) 위치가 H이면 들어간다.
const isHole = (r, c) => {
  return r === H.r && c === H.c;
}

const move = (red, blue, delta) => {
  let red_nr = red.r;
  let blue_nr = blue.r;
  let red_nc = red.c;
  let blue_nc = blue.c;

  let redDroped = false, blueDroped = false;

  for (let i = 1; i < Math.abs(delta.r) * N; ++i) {
    let redMovable = movable(red_nr + delta.r, red.c);
    let blueMovable = movable(blue_nr + delta.r, blue.c);

    // 레드가 가려는 곳에 블루가 있고, 블루가 움직이지 못하는 상황인 경우, 레드도 못 움직임.
    if (red_nc === blue_nc) {
      if (red_nr + delta.r === blue_nr && !blueMovable && !blueDroped) {
        redMovable = false;
      }
  
      if (blue_nr + delta.r === red_nr && !redMovable && !redDroped) {
        blueMovable = false;
      }
    }

    if (!redDroped && redMovable) {
      red_nr += delta.r;
    }
    if (!blueDroped && blueMovable) {
      blue_nr += delta.r;
    }
    
    if (isHole(red_nr, red.c)) redDroped = true;
    if (isHole(blue_nr, blue.c)) blueDroped = true;

    if (!redMovable && !blueMovable) break;
  }

  for (let i = 1; i < Math.abs(delta.c) * M; ++i) {
    let redMovable = movable(red.r, red_nc + delta.c);
    let blueMovable = movable(blue.r, blue_nc + delta.c);

    if (red_nr === blue_nr) {
      // 레드가 가려는 곳에 블루가 있고, 블루가 움직이지 못하는 상황인 경우, 레드도 못 움직임.
      if (red_nc + delta.c === blue_nc && !blueMovable && !blueDroped) {
        redMovable = false;
      }
  
      if (blue_nc + delta.c === red_nc && !redMovable && !redDroped) {
        blueMovable = false;
      }
    }

    if (!redDroped && redMovable) {
      red_nc += delta.c;
    }
    if (!blueDroped && blueMovable) {
      blue_nc += delta.c;
    }

    if (isHole(red.r, red_nc)) redDroped = true;
    if (isHole(blue.r, blue_nc)) blueDroped = true;

    if (!redMovable && !blueMovable) break;
  }

  return {
    red: {
      r: red_nr,
      c: red_nc,
    },
    blue: {
      r: blue_nr,
      c: blue_nc,
    }
  };
};

const mark = (red, blue, nRed, nBlue) => {
  [
    map[red.r][red.c],
    map[blue.r][blue.c],
    map[nRed.r][nRed.c],
    map[nBlue.r][nBlue.c]
  ] = [
    '.',
    '.',
    'R',
    'B'
  ];
}

const go = (red, blue, dist, prevDelta) => {
  if (isHole(blue.r, blue.c)) {
    return false;
  }

  if (isHole(red.r, red.c)) {
    return dist;
  }

  if (dist >= 10) {
    return false;
  }

  // console.log('-----------------');
  // console.log('dist: ', dist);
  // console.log(map.map(line => line.join('')).join('\n'));
  // console.log('-----------------');

  let minDist;

  for (const delta of deltas) {
    if (prevDelta) {
      // 이전 delta와 수직인 방향으로 기울이는 것만 의미가 있다.
      if (prevDelta.r * delta.r !== 0) continue;
      if (prevDelta.c * delta.c !== 0) continue;
    }

    const { red: nRed, blue: nBlue } = move(red, blue, delta);

    // 달라진 게 없다면 continue
    if (
      red.r === nRed.r && red.c === nRed.c &&
      blue.r === nBlue.r && blue.c === nBlue.c
    ) {
      continue;
    }

    mark(red, blue, nRed, nBlue);

    const res = go(nRed, nBlue, dist + 1, delta);

    if (res) {
      minDist = minDist ? Math.min(minDist, res) : res;
    }

    mark(nRed, nBlue, red, blue);
  }

  if (minDist) {
    return minDist;
  }

  return false;
};

const dist = go(R, B, 0);
// if (!dist || dist > 10) {
if (!dist) {
  console.log(-1);
} else {
  console.log(dist);
}
