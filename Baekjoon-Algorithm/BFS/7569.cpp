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
#define piii tuple<int, int, int>

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

int dr[] = {0, 0, 1, -1, 0, 0};
int dc[] = {1, -1, 0, 0, 0, 0};
int dh[] = {0, 0, 0, 0, 1, -1};

int dist[101][101][101];
int map[101][101][101];

int N, M, H;

void print() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << dist[0][i][j] << " ";
    }
    cout << "\n";
  }

  cout << "\n";

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << dist[1][i][j] << " ";
    }
    cout << "\n";
  }
}

int solve() {
  _FASTIOS;

  cin >> M >> N >> H;
  queue<piii> que;
  memset(dist, -1, sizeof(dist));

  for (int k = 0; k < H; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        cin >> map[k][i][j];
        if (map[k][i][j] == 1) {
          que.push(make_tuple(i, j, k));
          dist[k][i][j] = 0;
        }
      }
    }
  }

  int r, c, h;
  while (!que.empty()) {
    tie(r, c, h) = que.front(); que.pop();
    for (int k = 0; k < 6; ++k) {
      int nr = r + dr[k];
      int nc = c + dc[k];
      int nh = h + dh[k];

      if (nr >= N || nc >= M || nh >= H || nr < 0 || nc < 0 || nh < 0) continue;
      if (map[nh][nr][nc] == -1) continue;
      if (dist[nh][nr][nc] != -1) continue;

      dist[nh][nr][nc] = dist[h][r][c] + 1;
      que.push(make_tuple(nr, nc, nh));
    }
  }

  int ans = 0;

  // print();
  bool valid = true;

  for (int k = 0; k < H; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (dist[k][i][j] == -1 && map[k][i][j] == 0) {
          valid = false;
          break;
        }
        if (dist[k][i][j] != -1 && map[k][i][j] == 0) {
          ans = max(ans, dist[k][i][j]);
        }
      }
    }
  }

  cout << (!valid ? -1 : ans) << '\n';
  return 0;
}