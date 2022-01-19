const fs    = require('fs');
const map   = fs.readFileSync("/dev/stdin")
                            .toString()
                            .trim()
                            .split('\n');
// const map   = `
// ..###.##
// ##...#.#
// ..#.#..#
// #.#...#.
// .#...#.#
// .#.#..##
// #..#..#.
// ..#....#`.trim().split('\n');

const deltas = [
  // 4개 인접 방향
  { r: 0, c: 1 },
  { r: 0, c: -1 },
  { r: 1, c: 0 },
  { r: -1, c: 0 },
  // 4개 방향의 대각선
  { r: 1, c: 1 },
  { r: -1, c: -1 },
  { r: -1, c: 1 },
  { r: 1, c: -1 },
  // 가만히 있기
  { r: 0, c: 0 },
];

const visited = [];
for (let i = 0; i < 8; ++i) {
  visited[i] = [];
  for (let j = 0; j < 8; ++j) {
    visited[i][j] = [];
    for (let k = 0; k < 8; ++k) {
      visited[i][j][k] = false;
    }
  }
}

const go = () => {
  const que = [];
  que.push({
    time: 0,
    row: 7,
    col: 0,
  });
  
  while (que.length > 0) {
    const {row, col, time} = que.shift();
    const ntime = Math.min(8, time + 1);

    for (const delta of deltas) {
      const nr = row + delta.r;
      const nc = col + delta.c;

      // 도착점 도착
      if (nr === 0 && nc === 7) return true;

      // 범위 초과
      if (nr >= 8 || nc >= 8 || nr < 0 || nc < 0) continue;

      if (
        // 모든 벽을 실제로 map에 복사하면서 옮기는 게 아니라, nr, time으로 그 시간에 벽이 있는지 계산.
        // time초가 지났다면 nr에 벽이 없다는 걸 알 수 있기 때문에, nr < time인 경우 체크 안 해도 된다.
        (nr - time < 0 || map[nr - time][nc] === '.') &&
        // 마지막 row가 아니라면 다음 time에서 내려오는 벽도 고려해야 함.
        (nr - time - 1 < 0 || map[nr - time - 1][nc] === '.') &&
        // 같은 시간에 방문했던 적이 있는 곳은 방문하지 않음.
        !visited[nr][nc][time]
      ) {
        visited[nr][nc][time] = true;

        que.push({
          row: nr,
          col: nc,
          time: ntime
        });
      }
    }
  }

  return false;
};

console.log(go() ? 1 : 0);