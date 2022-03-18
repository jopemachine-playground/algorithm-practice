/*
==============================+===============================================================
@ Title : 타임머신
@ Desc : 음의 가중치를 가질 수 있기 때문에 벨만포드로 풀어야 하는 최단거리 문제.
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

struct Edge {
  int from;
  int to;
  int cost;
};

ll INF = 1e9;

ll dist[501];

int solve() {
  _FASTIOS;
  int N, M;
  cin >> N >> M;
  vector<Edge> graph(M);

  for (int i = 0; i < M; ++i) {
    cin >> graph[i].from >> graph[i].to >> graph[i].cost;
  }
  for (int i = 1; i <= N; ++i) {
    dist[i] = INF;
  }

  dist[1] = 0;
  bool hasNegativeCycle = false;

  // 최대 N-1번 돌아야 하고, 음수 사이클 판정을 위해 한 번 더 돈다.
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < M; ++j) {
      int from = graph[j].from;
      int to = graph[j].to;
      int cost = graph[j].cost;

      if (dist[from] != INF && dist[to] > dist[from] + cost) {
        dist[to] = dist[from] + cost;

        // N번째 완화에서 dist 값이 변경된다면 음의 사이클을 갖는다는 의미.
        if (i == N) {
          hasNegativeCycle = true;
        }
      }
    }
  }

  if (hasNegativeCycle) {
    cout << -1 << '\n';
  }
  else {
    for (int i = 2; i <= N; ++i) {
      if (dist[i] == INF) cout << -1 << "\n";
      else cout << dist[i] << "\n";
    }
  }

  return 0;
}