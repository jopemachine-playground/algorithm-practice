#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <tuple>
#include <algorithm>
#include <cstring>
#include <memory.h>

using namespace std;

int W, H;

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

vector<vector<int>> bfs(vector<vector<char>>& map, int r, int c) {
  vector<vector<int>> dist(map.size(), vector<int>(map[0].size(), -1));

  queue<pair<int, int>> que;
  que.push({ r, c });
  dist[r][c] = 0;

  while (!que.empty()) {
    tie(r, c) = que.front(); que.pop();

    for (int k = 0; k < 4; ++k) {
      int nr = r + dr[k];
      int nc = c + dc[k];

      if (nr >= H || nc >= W || nc < 0 || nr < 0) continue;
      if (dist[nr][nc] != -1) continue;
      if (map[nr][nc] == 'x') continue;
      dist[nr][nc] = dist[r][c] + 1;

      que.push({ nr, nc });
    }
  }

  return dist;
}

vector<pair<int, int>> findAllMarks (vector<vector<char>>& map) {
  // 0번째 지점엔 시작점을 넣자.
  vector<pair<int, int>> marks(1);

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++ j) {
      if (map[i][j] == 'o') {
        marks[0] = make_pair(i, j);
      } else if (map[i][j] == '*') {
        marks.push_back({ i, j });
      }
    }
  }

  return marks;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  while (true) {
    cin >> W >> H;
    if (W == 0 && H == 0) break;

    vector<vector<char>> map(H, vector<char>(W));

    for (int i = 0; i < H; ++i) {
      string str;
      cin >> str;
      for (int j = 0; j < W; ++j) {
        map[i][j] = str[j];
      }
    }

    vector<pair<int, int>> marks = findAllMarks(map);

    // 굳이 사차원 배열을 쓰지 않고도 marks.length에 해당하는 길이로 이차원 배열을 만들면
    // i번째 점에서 j번째 점으로 가는 거리를 저장할 수 있다.
    vector<vector<int>> dists(marks.size(), vector<int>(marks.size()));

    bool impossible = false;
    for (int i = 0; i < marks.size(); ++i) {
      int sr, sc;
      tie(sr, sc) = marks[i];

      auto distMap = bfs(map, sr, sc);
      for (int j = 0; j < marks.size(); ++ j) {
        dists[i][j] = distMap[marks[j].first][marks[j].second];
        if (dists[i][j] == -1) {
          impossible = true;
        }
      }
    }

    if (impossible) {
      cout << -1 << "\n";
      continue;
    }

    // marks에서 처음 점은 빼 줘야됨에 주의
    vector<int> moveOrders(marks.size() - 1);

    for (int i = 0; i < marks.size() - 1; ++i) {
      // 1번에서 시작
      moveOrders[i] = i + 1;
    }

    int result = 2000000000;

    do {
      // 처음 점을 빼 줬기 때문에 0번 점에서 0번의 도착점으로 가는 거리를 더해줘야함
      int sum = 0;
      sum += dists[0][moveOrders[0]];

      // i번째 점에서 시작해서 i+1번째 점으로 이동하는 거리를 더함
      for (int i = 0; i < moveOrders.size() - 1; ++i) {
        sum += dists[moveOrders[i]][moveOrders[i + 1]];
      }

      if (result > sum) result = sum;

    } while(next_permutation(moveOrders.begin(), moveOrders.end()));

    cout << result << "\n";
  }

  return 0;
}