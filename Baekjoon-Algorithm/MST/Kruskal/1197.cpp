/*
==============================+===============================================================
@ Title : 최소 스패닝 트리
@ Desc :
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

struct Edge {
  int from;
  int to;
  int cost;

  bool operator < (const Edge& rhs) const {
    return cost < rhs.cost;
  }
};

int parents[10001];

int find(int u) {
  if (u == parents[u]) return u;
  return parents[u] = find(parents[u]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  parents[u] = v;
}

int solve() {
  _FASTIOS;
  int V, E;
  cin >> V >> E;
  for (int i = 1; i <= V; ++i) {
    parents[i] = i;
  }

  vector<Edge> edges(E);

  for (int i = 0; i < E; ++i) {
    cin >> edges[i].from >> edges[i].to >> edges[i].cost;
  }

  sort(edges.begin(), edges.end());

  int ans = 0;
  for (int i = 0; i < E; ++i) {
    Edge edge = edges[i];
    int from = find(edge.from);
    int to = find(edge.to);
    if (from != to) {
      merge(edge.from, edge.to);
      ans += edge.cost;
    }
  }

  cout << ans << "\n";

  return 0;
}