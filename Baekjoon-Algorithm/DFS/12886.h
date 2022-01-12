#include <iostream>
#include <queue>

using namespace std;

bool check[1501][1501];

int sum;

void go (int x, int y) {
  if (check[x][y]) return;
  check[x][y] = true;
  int groups[3] = {x ,y, sum - x - y};

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (groups[i] < groups[j]) {
        int nextGroups[3] = {groups[0], groups[1], groups[2]};
        nextGroups[i] += groups[i];
        nextGroups[j] -= groups[i];
        // i, j 를 넘기든 0, 1을 넘기든 사실 똑같다..
        go (nextGroups[i], nextGroups[j]);
      }
    }
  }
}

int main () {
  int x, y, z;
  cin >> x >> y >> z;
  sum = x + y + z;
  if (sum % 3 != 0) {
    cout << 0 << '\n';
    return 0;
  }

  go(x, y);

  // 각 돌을 균등하게 나누었을 때가 체크되어 있는지 확인한다.
  if (check[sum / 3][sum / 3]) {
    cout << 1 << "\n";
  } else {
    cout << 0 << "\n";
  }

  return 0;
}