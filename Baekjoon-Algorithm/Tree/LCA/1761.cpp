/*
==============================+===============================================================
@ Title : 정점들의 거리
@ Desc : O(N)에 LCA를 구하는 알고리즘으로 풀린다.
트리 순회할 때 가중치가 있기 때문에 dist 배열을 따로 만들어서 그걸로 공식 만들어서 풀면 된다.
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

const int MAX = 40001;

vector<pii> graph[MAX];
bool visited[MAX];
int depth[MAX];
int dist[MAX];
int parents[MAX];

int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  while (depth[u] != depth[v]) {
    u = parents[u];
  }
  while (u != v) {
    u = parents[u];
    v = parents[v];
  }

  return u;
}

int solve() {
  _FASTIOS;
  int N;
  cin >> N;

  for (int i = 0; i < N - 1; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
  }

  depth[1] = 0;
  parents[1] = 0;
  visited[1] = true;
  queue<int> que;
  que.push(1);

  while (!que.empty()) {
    int curr = que.front();
    que.pop();

    int dest, cost;
    for (auto& pt: graph[curr]) {
      tie(dest, cost) = pt;
      if (visited[dest]) continue;
      visited[dest] = true;
      depth[dest] = depth[curr] + 1;
      dist[dest] = dist[curr] + cost;
      parents[dest] = curr;
      que.push(dest);
    }
  }

  int M;
  cin >> M;

  while (M--) {
    int u, v;
    cin >> u >> v;
    cout << dist[u] + dist[v] - 2 * dist[lca(u, v)] << '\n';
  }

  return 0;
}