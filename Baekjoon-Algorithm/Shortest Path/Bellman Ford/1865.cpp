/*
==============================+===============================================================
@ Title : 웜홀
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
};

int INF = 1e9;

int solve() {
  _FASTIOS;
  int TC;
  cin >> TC;
  while (TC--) {
    int N, M, W;
    cin >> N >> M >> W;
    vector<Edge> graph(2 * M + W);

    // 도로는 방향이 없으며, 웜홀은 방향이 있다.
    // => 2 * M + W개 만큼의 간선이 필요
    for (int i = 0; i < M; ++i) {
      cin >> graph[i].from >> graph[i].to >> graph[i].cost;
      graph[i + M] = graph[i];
      swap(graph[i + M].from, graph[i + M].to);
    }

    for (int i = 0; i < W; ++i) {
      int idx = 2 * M + i;
      cin >> graph[idx].from >> graph[idx].to >> graph[idx].cost;
      graph[idx].cost *= -1;
    }

    vector<int> dist(N + 1);
    // 한 지점에서 출발을 하여서 원래 자리로 돌아오기
    // 어떤 지점에서든지 출발이 가능 => 1번 부터 N번까지 모든 정점에서의 dist를 0으로.
    for (int i = 1; i <= N; ++i) {
      dist[i] = 0;
    }

    bool hasNegativeCycle = false;

    for (int i = 1; i <= N; ++i) {
      for (int j = 0; j < 2 * M + W; ++j) {
        int from = graph[j].from;
        int to = graph[j].to;
        int cost = graph[j].cost;

        if (dist[from] != INF && dist[to] > dist[from] + cost) {
          dist[to] = dist[from] + cost;

          if (i == N) {
            hasNegativeCycle = true;
          }
        }
      }
    }

    if (hasNegativeCycle) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}