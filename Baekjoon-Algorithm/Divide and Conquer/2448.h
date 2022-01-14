// https://andamiro25.tistory.com/76
#include <iostream>

using namespace std;

// 3 * 2 ^ 10 = 3072가 row의 최대 갯수.
// col의 최대 갯수는 두 배 더 큰 6144.
char map[3072][6144];

void star(int r, int c, int unit) {
  if (unit == 3) {
    map[r][c] = '*';
    map[r + 1][c - 1] = '*';
    map[r + 1][c + 1] = '*';
    map[r + 2][c - 2] = '*';
    map[r + 2][c - 1] = '*';
    map[r + 2][c] = '*';
    map[r + 2][c + 1] = '*';
    map[r + 2][c + 2] = '*';
    return;
  }

  star(r, c, unit / 2);
  star(r + (unit / 2), c - (unit / 2), unit / 2);
  star(r + (unit / 2), c + (unit / 2), unit / 2);
}

int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 2 * N; ++j) {
      map[i][j] = ' ';
    }
  }

  // row가 0에서 시작하는 건 당연한데,
  // col이 N - 1 에서 시작하는 게 와닿지 않았다.
  // 생각해보면 가장 큰 삼각형의 바로 아래 삼각형의 width가 맨 위 점의 x 좌표가 된다.
  star(0, N - 1, N);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 2 * N; ++j) {
      cout << map[i][j];
    }
    cout << endl;
  }

  return 0;
}