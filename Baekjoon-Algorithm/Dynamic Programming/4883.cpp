/*
==============================+===============================================================
@ Title : 삼각 그래프
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
#include <map>
#include <unordered_map>
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

const int M = 3;

int dr[] = {1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1};

int solve() {
  _FASTIOS;

  int idx = 1;

  while (true) {
    int N;
    cin >> N;

    int result = 0;
    int dp[N][M];
    int cost[N][M];
    bool visited[N][M];
    memset(visited, false, sizeof(bool) * N * M);

    if (N == 0) break;

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        cin >> cost[i][j];
      }
    }

    // first line
    dp[0][0] = 0;
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][1] + cost[0][2];

    // second line
    dp[1][0] = dp[0][1] + cost[1][0];
    dp[1][1] = min(dp[0][1] + cost[1][1], dp[0][1] + cost[0][2] + cost[1][1]);
    dp[1][2] = min({
        dp[0][1] + cost[1][2],
        dp[0][1] + cost[0][2] + cost[1][2],
        dp[0][1] + cost[0][2] + cost[1][1] + cost[1][2],
        dp[0][1] + cost[1][1] + cost[1][2]
    });

    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < M; ++j) {
        visited[i][j] = true;
      }
    }

    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < M; ++j) {

        for (int k = 0; k < 4; ++k) {
          int nr = i + dr[k];
          int nc = j + dc[k];
          if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

          int nextCost = dp[i][j] + cost[nr][nc];

          if (!visited[nr][nc] || dp[nr][nc] > nextCost) {
            visited[nr][nc] = true;
            dp[nr][nc] = nextCost;
          }
        }
      }
    }

    cout << idx++ << "." << " " << dp[N - 1][1] << "\n";
  }

  return 0;
}
