/*
==============================+===============================================================
@ Title : K번째 최단경로 찾기
@ Desc : 1162 (도로 포장) 문제처럼 정점의 정의를 확장시켜서 푸는 것과 유사하다고 느껴졌다.
다만, 시간 복잡도를 위해 배열로 확장하는게 아니라 최대 힙을 사용해야 하고,
큐에 따로 더 들어가야 하는 건 없다.
정점의 정의를 확장한다고 해도 어떻게 확장할 지 생각하는 것도 어려운 것 같다.
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
  int to, cost;
  Edge(int to, int cost): to(to), cost(cost) {};
};

vector<Edge> graph[1001];
priority_queue<int> dists[1001];

const int INF = 2e9;

int solve()
{
  _FASTIOS;
  int N, M, K;
  cin >> N >> M >> K;

  for (int i = 0; i < M; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    graph[from].push_back(Edge(to, cost));
  }

  dists[1].push(0);

  priority_queue<pii> pq;
  pq.push({ 0, 1 });

  int cost, curr;
  while (!pq.empty()) {
    tie(cost, curr) = pq.top(); pq.pop();
    cost = -cost;
    vector<Edge>& linkedList = graph[curr];

    for (int i = 0; i < linkedList.size(); ++i) {
      int to = linkedList[i].to;
      int nextCost = cost + linkedList[i].cost;

      if (dists[to].size() < K || dists[to].top() > nextCost) {
        if (dists[to].size() >= K) {
          dists[to].pop();
        }

        dists[to].push(nextCost);
        pq.push({ -nextCost, to });
      }
    }
  }

  for (int i = 1; i <= N; ++i) {
    if (dists[i].size() < K) {
      cout << -1 << '\n';
    } else {
      cout << dists[i].top() << '\n';
    }
  }

  return 0;
}