#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <unordered_set>
#include <tuple>
#include <algorithm>
#include <array>
#include <memory.h>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define debug if constexpr (LOCAL) cout
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
#define endl '\n'
#define ll long long
#define pii pair<int, int>

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int dist[1001][1001];
int map[1001][1001];

int N, M;

void print() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << dist[i][j] << " ";
    }
    cout << '\n';
  }
}

int solve() {
  _FASTIOS;

  cin >> M >> N;
  queue<pii> que;
  memset(dist, -1, sizeof(dist));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> map[i][j];
      if (map[i][j] == 1) {
        que.push({ i, j });
        dist[i][j] = 0;
      }
    }
  }

  int r, c;
  while (!que.empty()) {
    tie(r, c) = que.front(); que.pop();
    for (int k = 0; k < 4; ++k) {
      int nr = r + dr[k];
      int nc = c + dc[k];
      if (nr >= N || nc >= M || nr < 0 || nc < 0) continue;
      if (map[nr][nc] == -1) continue;
      if (dist[nr][nc] != -1) continue;

      dist[nr][nc] = dist[r][c] + 1;
      que.push({ nr, nc });
    }
  }

  int ans = 0;

  // print();
  bool valid = true;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (dist[i][j] == -1 && map[i][j] == 0) {
        valid = false;
        break;
      }
      if (dist[i][j] != -1 && map[i][j] == 0) {
        ans = max(ans, dist[i][j]);
      }
    }
  }

  cout << (!valid ? -1 : ans) << '\n';
  return 0;
}