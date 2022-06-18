/*
==============================+===============================================================
@ Title : 내리막 길
@ Desc :
@ Ref :
==============================+===============================================================
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <memory.h>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define debug                                                                  \
  if constexpr (LOCAL)                                                         \
  cout
#define _FASTIOS cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(0)
#define endl '\n'
#define ll long long
#define pii pair<int, int>

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

int N, M;
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int graph[501][501];
int dp[501][501];

int dfs(int r, int c) {
  if (r == N - 1 && c == M - 1) {
    return 1;
  }

  int &ans = dp[r][c];
  if (ans != -1) return ans;
  ans = 0;

  for (int k = 0; k < 4; ++k) {
    int nr = r + dr[k];
    int nc = c + dc[k];

    if (graph[nr][nc] >= graph[r][c])
      continue;

    if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
      ans += dfs(nr, nc);
    }
  }

  return ans;
}

int solve() {
  _FASTIOS;

  cin >> N >> M;
  memset(dp, -1, sizeof(int) * 501 * 501);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> graph[i][j];
    }
  }

  dfs(0, 0);

  // for (int i = 0; i < N; ++i) {
  //   for (int j = 0; j < M; ++j) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  cout << dp[0][0] << "\n";

  return 0;
}
