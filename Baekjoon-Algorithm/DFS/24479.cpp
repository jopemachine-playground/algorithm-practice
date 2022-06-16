/*
==============================+===============================================================
@ Title : 알고리즘 수업 - 깊이 우선 탐색 1
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

int visited[100001];

int order = 1;

void dfs(vector<vector<int>> &graph, vector<int> &result, int node) {
  if (!visited[node]) {
    result[node] = order++;
    visited[node] = true;
    for (auto pt : graph[node]) {
      dfs(graph, result, pt);
    }
  }
}

int solve() {
  _FASTIOS;
  int N, M, R;
  cin >> N >> M >> R;

  // linked list graph
  vector<vector<int>> graph(N + 1, vector<int>());

  // visit order
  vector<int> result(N + 1, 0);

  while (M--) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i = 1; i <= N; ++i) {
    sort(graph[i].begin(), graph[i].end());
  }

  dfs(graph, result, R);

  for (int i = 1; i <= N; ++i) {
    cout << result[i] << "\n";
  }

  return 0;
}
