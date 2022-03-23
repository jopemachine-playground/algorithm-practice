/*
==============================+===============================================================
@ Title : 도로포장
@ Desc : 도로를 포장할지 말지를 따로 갖고 있는게 아니라, 정점의 정의에 포함시켜서
dist, visited에 한 차원을 늘려줘야 한다.
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

struct Edge {
  int to;
  int cost;
  Edge(int to, int cost): to(to), cost(cost) {};
};

vector<Edge> graph[10001];

bool visited[10001][21];
ll dist[10001][21];

const ll INF = 1e9 * 50000LL;

int solve()
{
  _FASTIOS;
  int N, M, K;
  cin >> N >> M >> K;

  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= K; ++j) {
      dist[i][j] = INF;
    }
  }

  for (int i = 0; i < M; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    graph[from].push_back(Edge(to, cost));
    graph[to].push_back(Edge(from, cost));
  }

  dist[1][0] = 0;
  // cost, dest, step
  priority_queue<tuple<ll, int, int>> que;
  que.push(make_tuple(0, 1, 0));

  int cost, dest, step;
  while (!que.empty()) {
    tie(cost, dest, step) = que.top(); que.pop();
    vector<Edge>& linkedList = graph[dest];

    if (visited[dest][step]) continue;
    visited[dest][step] = true;
    
    for (Edge edge : linkedList) {
      // 도로 포장을 안 하는 경우
      if (dist[edge.to][step] > dist[dest][step] + edge.cost) {
        dist[edge.to][step] = dist[dest][step] + edge.cost;
        que.push(make_tuple( -dist[edge.to][step], edge.to, step ));
      }
      // 도로 포장을 하는 경우
      if (step + 1 <= K && dist[edge.to][step + 1] > dist[dest][step]) {
        dist[edge.to][step + 1] = dist[dest][step];
        que.push(make_tuple( -dist[edge.to][step + 1], edge.to, step + 1 ));
      }
    }
  }

  ll ans = INF;
  for (int i = 0; i <= K; ++i) {
    if (visited[N][i]) {
      ans = min(ans, dist[N][i]);
    }
  }

  cout << ans << '\n';

  return 0;
}