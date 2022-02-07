// Ref: https://peisea0830.tistory.com/98
#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <tuple>
#include <algorithm>
#include <memory.h>

using namespace std;

int N;

// 두 점 중 하나만 찾으면 된다.
pair<int, int> findStart(vector<vector<char>>& map) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++ j) {
      if (map[i][j] == '#') {
        return make_pair(i, j);
      }
    }
  }
  return {-1,-1};
}

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N;

  vector<vector<char>> map(N, vector<char>(N));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++ j) {
      cin >> map[i][j];
    }
  }

  pair<int, int> start = findStart(map);

  // 거울을 지나갈 때 가중치 1 증가, 지나가지 않는 경우 0
  deque<tuple<int, int, int>> que;

  // dist를 이차원 배열로 만들면 중복 방문 체크를 올바르게 할 수 없음.
  // => 해당 위치를 지나갔을 때의 방향 (k)을 함께 기록해 3차원 배열로 만들자
  vector<vector<vector<int>>> dist(N, vector<vector<int>>(N, vector<int>(4, -1)));
  int result = 2000000000;

  // 시작 지점에서 방향을 결정해줘야 하는 경우, 
  // 매번 처음만 예외 처리하는 것 보다 반복문을 바깥으로 빼 내 주는 편이
  // 더 코드가 간단해 지는 것 같다.
  for (int i = 0; i < 4; ++i) {
    que.push_back(make_tuple(start.first, start.second, i));

    dist[start.first][start.second][i] = 0;

    while (!que.empty()) {
      int r, c, k;
      tie(r, c, k) = que.front(); que.pop_front();

      if (
        (r != start.first || c != start.second) &&
        map[r][c] == '#'
      ) {
        if (result > dist[r][c][k]) {
          result = dist[r][c][k];
          continue;
        }
      }

      int nr = r + dr[k];
      int nc = c + dc[k];

      if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
      if (map[nr][nc] == '*') continue;

      // 거울이 있는 경우 수직으로 꺽어서 갈 수도, 같은 방향으로 갈 수도 있고,
      // 거울이 없는 경우 같은 방향으로만 갈 수 있다.
      // dist 값은 거울을 만날 때만 증가시킨다.

      // 일반적인 BFS의 경우 dist가 -1일 때만 진행해야 하지만,
      // 0-1 BFS에서 dist가 더 적은 경우 더 적은 쪽으로 갱신해줘야 하는 것 같다.
      if (
        dist[nr][nc][k] == -1 ||
        dist[nr][nc][k] > dist[r][c][k]
      ) {
        dist[nr][nc][k] = dist[r][c][k];
        que.push_front(make_tuple(nr, nc, k));
      }

      if (map[nr][nc] == '!') {
        // 수직인 방향을 구함
        vector<int> nks(2);
        if (k == 0 || k == 1) {
          nks.push_back(2);
          nks.push_back(3);
        } else {
          nks.push_back(0);
          nks.push_back(1);
        }

        for (int nk : nks) {
          if (dist[nr][nc][nk] == -1) {
            dist[nr][nc][nk] = dist[r][c][k] + 1;
            que.push_back(make_tuple(nr, nc, nk));
          }
        }
      }
    }
  }

  cout << result << "\n";

  return 0;
}