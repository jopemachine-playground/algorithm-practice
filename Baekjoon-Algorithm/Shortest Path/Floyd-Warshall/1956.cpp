/*
==============================+===============================================================
@ Title : 운동
@ Desc : 도로의 길이의 합이 가장 작은 사이클을 찾아라.
=> i에서 i로 가는 최단거리의 합이 가장 작은 경로를 찾아라
=> 모든 쌍 최단 거리 알고리즘으로 접근해라.
@ Ref : 백준 알고리즘 중급
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

#define debug          \
  if constexpr (LOCAL) \
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

int dists[401][401];

const int INF = 1e9;

int solve()
{
  _FASTIOS;
  int V, E;
  cin >> V >> E;

  for (int i = 1; i <= V; ++i) {
    for (int j = 1; j <= V; ++j) {
      dists[i][j] = INF;
    }
  }

  for (int i = 0; i < E; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    dists[from][to] = cost;
  }

  for (int k = 1; k <= V; ++k) {
    for (int i = 1; i <= V; ++i) {
      for (int j = 1; j <= V; ++j) {
        dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
      }
    }
  }

  int ans = INF;
  for (int i = 1; i <= V; ++i) {
    ans = min(ans, dists[i][i]);
  }

  cout << (ans == INF ? -1 : ans) << '\n';

  return 0;
}