// 백준 알고리즘 강의 중급
#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
  int M, N;
  cin >> M >> N;
  vector<string> map(N);
  int sx, sy, ex, ey;
  sx = sy = ex = ey = -1;
  for (int i = 0; i < N; ++i) {
    cin >> map[i];
    for (int j = 0; j < M; ++j) {
      if (map[i][j] == 'C') {
        if (sx == -1) {
          sx = i;
          sy = j;
        }
        else {
          ex = i;
          ey = j;
        }
      }
    }
  }

  vector<vector<int>> d(N, vector<int>(M, -1));
  queue<pair<int, int>> q;
  d[sx][sy] = 0;

  q.push({ sx, sy });

  while (!q.empty()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();
    for (int k = 0; k < 4; ++k) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      while (0 <= nx && nx < N && 0 <= ny && ny < M) {
        if (map[nx][ny] == '*') break;
        if (d[nx][ny] == -1) {
          d[nx][ny] = d[x][y] + 1;
          q.push({ nx, ny });
        }

        nx += dx[k];
        ny += dy[k];
      }
    }
  }

  cout << d[ex][ey] - 1 << "\n";
  return 0;
}