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

int N, M;
int dr[] = {0,0,1,-1}; 
int dc[] = {1,-1,0,0};
int dist[1001][1001][2];
int map[1001][1001];

int solve() {
  _FASTIOS;
  cin >> N >> M;
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
      if (dist[nr][nc][k] != -1) continue;

      if (map[nr][nc] == 1) {
        if (k == 0) {
          dist[nr][nc][1] = dist[r][c][0] + 1;
          que.push(make_tuple(nr, nc, k + 1));
        }
      } else {
        dist[nr][nc][k] = dist[r][c][k] + 1;
        que.push(make_tuple(nr, nc, k));
      }
    }
  }

  int cand1 = dist[N - 1][M - 1][0];
  cand1 = cand1 == -1 ? 2e9 : cand1;

  int cand2 = dist[N - 1][M - 1][1];
  cand2 = cand2 == -1 ? 2e9 : cand2;

  if (cand1 == 2e9 && cand2 == 2e9) cout << -1 << '\n';
  else cout << min(cand1, cand2) << '\n';

  return 0;
}