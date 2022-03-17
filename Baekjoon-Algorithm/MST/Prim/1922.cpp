/*
==============================+===============================================================
@ Title : 네트워크 연결
@ Desc : MST를 이용해 풀 수 있는 대표적인 문제. 프림 알고리즘 사용.
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
  int to;
  int cost;
  // 최소 힙으로 만들어 주기 위한 operator 오버로딩
  bool operator < (const Edge& rhs) const {
    return cost > rhs.cost;
  }
};

vector<Edge> graph[1001];

bool visited[1001];

int solve() {
  _FASTIOS;
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int A, B, C;
    cin >> A >> B >> C;
    graph[A].push_back(Edge({B, C}));
    graph[B].push_back(Edge({A, C}));
  }

  visited[1] = true;
  priority_queue<Edge> pque;

  // 우선 1번 정점의 모든 간선들을 pque에 넣음.
  for (Edge edge: graph[1]) {
    pque.push(edge);
  }

  int ans = 0;

  while (!pque.empty()) {
    Edge edge = pque.top();
    pque.pop();
    if (visited[edge.to]) continue;
    visited[edge.to] = true;
    ans += edge.cost;

    for (Edge nextEdge : graph[edge.to]) {
      pque.push(nextEdge);
    }
  }

  cout << ans << "\n";

  return 0;
}