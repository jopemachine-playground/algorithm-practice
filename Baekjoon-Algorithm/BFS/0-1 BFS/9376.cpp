#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#include <deque>

using namespace std;

int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

vector<pair<int,int>> findStarts (vector<vector<char>>& map) {
  vector<pair<int,int>> result;

  for (int i = 0; i < map.size(); ++i) {
    for (int j = 0; j < map[0].size(); ++j) {
      // BFS 문제에서 시작점은 빈칸과 동일한 의미를 가질 때가 많음
      // => 그냥 .으로 바꿔놓으면 편하다.
      if (map[i][j] == '$') {
        result.push_back({ i, j });
        map[i][j] = '.';
      }
    }
  }

  return result;
}

void printMap(vector<vector<char>>& map) {
  for (int i = 0; i < map.size(); ++i) {
    for (int j = 0; j < map[0].size(); ++j) {
      if (map[i][j] == -1) cout << 0 << ' ';
      else cout << map[i][j] << ' ';
    }
    cout << '\n';
  }
}

void printMap(vector<vector<int>>& map) {
  for (int i = 0; i < map.size(); ++i) {
    for (int j = 0; j < map[0].size(); ++j) {
      if (map[i][j] == -1) cout << 0 << ' ';
      else cout << map[i][j] << ' ';
    }
    cout << '\n';
  }
}

inline bool checkRange(vector<vector<char>>& map, int r, int c) {
  return r >= 0 && c >= 0 && r < map.size() && c < map[0].size();
}

vector<vector<int>> bfs(vector<vector<char>>& map, int r, int c) {
  vector<vector<int>> dist(map.size(), vector<int>(map[0].size(), -1));

  deque<pair<int, int>> que;
  que.push_back({ r, c });
  dist[r][c] = 0;

  while (que.size() > 0) {
    tie(r, c) = que.front(); que.pop_front();

    for (int dir = 0; dir < 4; ++dir) {
      int nr = r + dr[dir];
      int nc = c + dc[dir];

      if (!checkRange(map, nr, nc)) continue;
      if (dist[nr][nc] != -1) continue;
      if (map[nr][nc] == '*') continue;

      if (map[nr][nc] == '#') {
        dist[nr][nc] = dist[r][c] + 1;
        que.push_back({ nr, nc });
      } else if (map[nr][nc] == '.') {
        dist[nr][nc] = dist[r][c];
        que.push_front({ nr, nc });
      }
    }
  }

  return dist;
}

// int main () {
int solve () {
  int T, H, W;
  ios::sync_with_stdio(false);

  cin.tie(NULL);
  cin >> T;

  while (T-- > 0) {
    cin >> H >> W;
    // BFS로 풀기 위해 그래프 변형.
    // 바깥 쪽을 . 으로 둘러쌀 것임.
    vector<vector<char>> map(H + 2, vector<char>(W + 2, '.'));

    // 그래프 입력
    for (int i = 1; i < H + 1; ++i) {
      for (int j = 1; j < W + 1; ++j) {
        cin >> map[i][j];
      }
    }

    // printMap(map);

    auto starts = findStarts(map);

    // cout << "----------------" << "\n";
    // cout << starts[0].first << "\n";
    // cout << starts[0].second << "\n";

    auto distMap1 = bfs(map, starts[0].first, starts[0].second);
    auto distMap2 = bfs(map, starts[1].first, starts[1].second);
    auto distMap3 = bfs(map, 0, 0);
    // printMap(distMap3);

    // 디버깅 용
    vector<vector<int>> dist(H+2, vector<int>(W+2, -1));

    // 최댓값은 모든 점이 문인 경우
    int result = (H + 2) * (W + 2);
    for (int i = 0; i < map.size(); ++i) {
      for (int j = 0; j < map[0].size(); ++j) {
        if (map[i][j] == '*') continue;
        if (distMap1[i][j] == -1 || distMap2[i][j] == -1 || distMap3[i][j] == -1) continue;
        int d = distMap1[i][j] + distMap2[i][j] + distMap3[i][j];

        if (map[i][j] == '#') d = d - 2;

        dist[i][j] = d;
        if (result > d) result = d;
      }
    }

    // printMap(dist);

    cout << result << "\n";
  }
  return 0;
}