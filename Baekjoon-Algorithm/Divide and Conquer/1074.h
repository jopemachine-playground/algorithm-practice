#include <iostream>

using namespace std;

int N, r, c;

int ans = 0;

void go (int row, int col, int unit) {
  if (row == r && col == c) {
    cout << ans << "\n";
    return;
  }

  const int nextUnit = unit >> 1;

  if (r < row + unit && r >= row && c < col + unit && c >= col) {
    // 주의: Z 순서로 탐색해야 함.
    go(row, col, nextUnit);
    go(row, col + nextUnit, nextUnit);
    go(row + nextUnit, col, nextUnit);
    go(row + nextUnit, col + nextUnit, nextUnit);
  }

  // 모든 칸들을 방문할 필요 없이 타겟 값이 없는 사분면들에선 unit * unit을 더해주면서 진행하면 된다.
  else {
    ans += unit * unit;
  }
}

int solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> r >> c;
  go(0, 0, (1 << N));
  return 0;
}