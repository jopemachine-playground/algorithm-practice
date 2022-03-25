/*
==============================+===============================================================
@ Title : 도시 분할 계획
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
  int from, to, cost;
  bool operator < (const Edge& rhs) const {
    return cost < rhs.cost;
  }
};

int parents[100001];

int find (int u) {
  if (parents[u] == u) return u;
  return parents[u] = find(parents[u]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  parents[u] = v;
}

int solve() {
  _FASTIOS;
  int N, M;
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    parents[i] = i;
  }

  vector<Edge> graph(M);

  for (int i = 0; i < M; ++i) {
    cin >> graph[i].from >> graph[i].to >> graph[i].cost;
  }

  sort(graph.begin(), graph.end());

  int ans = 0;
  int edgeCnt = 0;

  for (int i = 0; i < M; ++i) {
    Edge edge = graph[i];
    int from = find(edge.from);
    int to = find(edge.to);

    if (from != to) {
      merge(from, to);
      ans += edge.cost;
      ++edgeCnt;
    }
    // N - 1 번째 간선이 MST의 마지막 간선,
    // 가장 큰 간선이므로 해당 간선을 추가하지 않으면 문제 조건에 부합할 수 있다.
    if (edgeCnt == N - 2) break;
  }

  cout << ans << '\n';

  return 0;
}