/*
==============================+===============================================================
@ Title : 알고리즘 수업 - 너비 우선 탐색 2
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

int orders[100001];

int solve() {
  _FASTIOS;

  int N, M, R;
  cin >> N >> M >> R;

  vector<vector<int>> graph(N + 1);

  while (M--) {
    int s, e;
    cin >> s >> e;
    graph[s].push_back(e);
    graph[e].push_back(s);
  }

  for (int i = 1; i <= N; ++i) {
    sort(graph[i].begin(), graph[i].end(), greater<>());
  }

  queue<int> que;
  que.push(R);

  bool visited[N + 1];
  memset(visited, false, sizeof visited);

  int order = 1;
  while (!que.empty()) {
    int top = que.front();
    que.pop();
    if (visited[top]) continue;
    visited[top] = true;
    orders[top] = order++;

    for (int nextPt : graph[top]) {
      que.push(nextPt);
    }
  }

  for (int i = 1; i <= N; ++i) {
    cout << orders[i] << "\n";
  }

  return 0;
}
