/*
==============================+===============================================================
@ Title : 벽 부수고 이동하기 3
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
#define piiii tuple<int, int, int, int>

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

int N, M, K;
int dr[] = {0,0,1,-1,0}; 
int dc[] = {1,-1,0,0,0};
int dist[1001][1001][11][2];
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

  queue<piiii> que;
  // 낮에서 시작
  que.push(make_tuple(0, 0, 0, 0));
  dist[0][0][0][0] = 1;

  int r,c,k,isNight;
  while (!que.empty()) {
    tie(r, c, k, isNight) = que.front(); que.pop();
    for (int i = 0; i < 5; ++i) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (nr >= N || nc >= M || nc < 0 || nr < 0) continue;

      if (map[nr][nc] == 1) {
        if (k < K && !isNight) {
          int& next = dist[nr][nc][k + 1][1 - isNight];
          if (next != -1) continue;
          next = dist[r][c][k][isNight] + 1;
          que.push(make_tuple(nr, nc, k + 1, 1 - isNight));
        }
      }

      // 밤이면 가만히 있을 수 있음.
      if (map[nr][nc] == 0 || (map[nr][nc] == 1 && i == 4)) {
        int& next = dist[nr][nc][k][1 - isNight];
        if (next != -1) continue;
        next = dist[r][c][k][isNight] + 1;
        que.push(make_tuple(nr, nc, k, 1 - isNight));
      }
    }
  }

  int ans = 2e9;
  for (int i = 0; i <= 10; ++i) {
    if (dist[N - 1][M - 1][i][0] != -1) {
      ans = min(ans, dist[N - 1][M - 1][i][0]);
    }
    if (dist[N - 1][M - 1][i][1] != -1) {
      ans = min(ans, dist[N - 1][M - 1][i][1]);
    }
  }

  cout << (ans == 2e9 ? -1 : ans) << '\n';

  return 0;
}