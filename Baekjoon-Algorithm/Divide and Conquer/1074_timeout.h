#include <iostream>

using namespace std;

int N, r, c;

int idx = -1;

const int deltaXs[] = { 0, 0, 1, 1 };
const int deltaYs[] = { 0, 1, 0, 1 };

void go (int row, int col, int unit) {
  // Z 순으로 방문해야 한다길래 unit이 2일 땐 따로 예외처리를 해 줘야하는 줄 알았다..
  // 사실 아래 로직은 필요 없고, go를 Z 순서로 호출하기만 하면 된다.
  // 그리고 애초에 아래처럼 모든 칸들을 방문하면서 idx를 1씩 증가시키는 방식으로 풀면 반드시 시간 초과가 난다.
  if (unit == 2) {
    for (int deltaIdx = 0; deltaIdx < 4; ++deltaIdx) {
      ++idx;
      const int deltaX = deltaXs[deltaIdx];
      const int deltaY = deltaYs[deltaIdx];

      if (row + deltaX == r && col + deltaY == c) {
        cout << idx << '\n';
        break;
      }
    }
    return;
  }

  const int nextUnit = unit >> 1;

  go(row, col, nextUnit);
  go(row, col + nextUnit, nextUnit);
  go(row + nextUnit, col, nextUnit);
  go(row + nextUnit, col + nextUnit, nextUnit);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> r >> c;
  go(0, 0, (1 << N));
  return 0;
}