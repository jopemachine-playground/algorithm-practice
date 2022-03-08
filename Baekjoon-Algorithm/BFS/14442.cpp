/*
==============================+===============================================================
@ Title : 벽 부수고 이동하기
@ Desc :
@ Ref :
==============================+===============================================================
*/

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

int N, M, K;
int dr[] = {0,0,1,-1}; 
int dc[] = {1,-1,0,0};
int dist[1001][1001][11];
int map[1001][1001];

int solve() {
  _FASTIOS;
  cin >> N >> M >> K;
  memset(dist, -1, sizeof dist);

  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    for (int j = 0; j < M; ++j) {
      map[i][j] = str[j] - '0';
    }
  }

  queue<piii> que;
  que.push(make_tuple(0, 0, 0));
  dist[0][0][0] = 1;

  int r,c,k;
  while (!que.empty()) {
    tie(r, c, k) = que.front(); que.pop();
    for (int i = 0; i < 4; ++i) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (nr >= N || nc >= M || nc < 0 || nr < 0) continue;

      if (map[nr][nc] == 1) {
        if (k < K) {
          if (dist[nr][nc][k + 1] != -1) continue;
          dist[nr][nc][k + 1] = dist[r][c][k] + 1;
          que.push(make_tuple(nr, nc, k + 1));
        }
      } else {
        if (dist[nr][nc][k] != -1) continue;
        dist[nr][nc][k] = dist[r][c][k] + 1;
        que.push(make_tuple(nr, nc, k));
      }
    }
  }

  int ans = 2e9;
  for (int i = 0; i <= 10; ++i) {
    if (dist[N - 1][M - 1][i] == -1) continue;
    ans = min(ans, dist[N - 1][M - 1][i]);
  }

  cout << (ans == 2e9 ? -1 : ans) << '\n';

  return 0;
}