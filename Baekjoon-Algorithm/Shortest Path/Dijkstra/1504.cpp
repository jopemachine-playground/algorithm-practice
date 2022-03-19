/*
==============================+===============================================================
@ Title : 특정한 최단 경로
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

int N, E;

struct Edge {
  int to;
  int cost;
  Edge(int to, int cost): to(to), cost(cost) {};
};

vector<Edge> graph[801];
bool visited[801];
int dist[801];

int INF = 1e9;

int go(int start, int end) {
  memset(visited, 0, sizeof(visited));

  for (int i = 1; i <= N; ++i) {
    dist[i] = INF;
  }

  dist[start] = 0;

  // w, i
  priority_queue<pii> pq;
  pq.push({ 0, start });
  int cost, pos;

  while (!pq.empty()) {
    tie (cost, pos) = pq.top();
    pq.pop();
    if (visited[pos]) continue;
    visited[pos] = true;

    vector<Edge>& linkedList = graph[pos];

    for (int i = 0; i < linkedList.size(); ++i) {
      int to = linkedList[i].to;
      if (dist[to] > dist[pos] + linkedList[i].cost) {
        dist[to] = dist[pos] + linkedList[i].cost;
        pq.push({ -dist[to], to });
      }
    }
  }

  return dist[end];
}

int solve() {
  _FASTIOS;
  cin >> N >> E;
  for (int i = 0; i < E; ++i) {
    int s, e, w;
    cin >> s >> e >> w;
    graph[s].push_back(Edge(e, w));
    graph[e].push_back(Edge(s, w));
  }

  int X, Y;
  cin >> X >> Y;
  int method1, method2;

  int res1 = go (1, X);
  int res2 = go (X, Y);
  int res3 = go (Y, N);

  if (res1 == INF || res2 == INF || res3 == INF) method1 = INF;
  else method1 = res1 + res2 + res3;

  res1 = go(1, Y);
  res2 = go(Y, X);
  res3 = go(X, N);

  if (res1 == INF || res2 == INF || res3 == INF) method2 = INF;
  else method2 = res1 + res2 + res3;

  int res = min(method1, method2);
  cout << (res == INF ? -1 : res) << '\n';

  return 0;
}