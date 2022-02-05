#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <tuple>
#include <algorithm>
#include <memory.h>

using namespace std;

int N, M;
int dr[] = {0,0,1,-1,1,-1,1,-1};
int dc[] = {1,-1,0,0,1,-1,-1,1};

int map[51][51];

int bfs(int r, int c) {
  int dist[51][51];
  memset(dist, -1, sizeof(dist));

  queue<pair<int, int>> que;
  dist[r][c] = 0;

  que.push({ r, c });

  while(!que.empty()) {
    tie(r, c) = que.front(); que.pop();

    for (int k = 0; k < 8; ++k) {
      int nr = r + dr[k];
      int nc = c + dc[k];

      if (dist[nr][nc] != -1) continue;

      dist[nr][nc] = dist[r][c] + 1;

      // 상어 만나자 마자 리턴
      if (map[nr][nc] == 1) return dist[nr][nc];

      que.push({ nr, nc });
    }
  }

  // 아기 상어가 한 마리도 없는 경우는 별개로 처리해주자..
  // (안전거리 0으로 정의됨)
  return 0;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++ j) {
      cin >> map[i][j];
    }
  }

  int maxDist = 0;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++ j) {
      if (map[i][j] == 0) {
        int dist = bfs(i, j);
        // cout << dist << "\n";
        if (maxDist < dist) maxDist = dist;
      }
    }
  }

  cout << maxDist << "\n";

  return 0;
}