/*
==============================+===============================================================
@ Title : 임계경로
@ Desc : '작업' 문제에서 좀 더 발전된 문제.
정점 가중치의 합의 최대 경로를 찾고, 그 때 해당 경로가 포함하는 간선 갯수를 모두 구하는 문제.
그래프의 간선 방향을 반대로 해서 위상 정렬을 한 번 더 돌리면서 
cost 차이가 적절한 정점을 임계 경로에 하나 씩 추가해주면 된다.
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

int solve() {
  _FASTIOS;
  int V, E;
  cin >> V >> E;

  vector<pii> graph[V + 1];
  // 간선의 방향이 반대인 그래프를 하나 더 만든다.
  vector<pii> r_graph[V + 1];

  vector<int> dist(V + 1, 0);

  // 해당 정점이 임계 경로에 포함되어 있는지 여부
  vector<bool> isInside(V + 1, false);

  vector<int> indegree(V + 1, 0);
  vector<int> r_indegree(V + 1, 0);

  for (int i = 0; i < E; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    graph[from].push_back({to, cost});
    r_graph[to].push_back({from, cost});

    indegree[to]++;
    r_indegree[from]++;
  }

  int start, end;
  cin >> start >> end;

  queue<int> que;

  for (int i = 1; i <= V; ++i) {
    if (indegree[i] == 0) {
      que.push(i);
    }
  }

  while (!que.empty()) {
    int curr = que.front(); que.pop();
    vector<pii>& linkedList = graph[curr];
    for (int i = 0; i < linkedList.size(); ++i) {
      int dest = linkedList[i].first;
      dist[dest] = max(dist[dest], dist[curr] + linkedList[i].second);
      --indegree[dest];
      if (indegree[dest] == 0) {
        que.push(dest);
      }
    }
  }

  cout << dist[end] << '\n';
  isInside[end] = true;

  for (int i = 1; i <= V; ++i) {
    if (r_indegree[i] == 0) {
      que.push(i);
    }
  }

  int ans = 0;

  while (!que.empty()) {
    int curr = que.front(); que.pop();
    vector<pii>& linkedList = r_graph[curr];

    int dest, cost;
    for (int i = 0; i < linkedList.size(); ++i) {
      tie(dest, cost) = linkedList[i];
      // curr가 임계 경로에 포함되는 정점이고,
      // 거리 차가 cost와 같다면 dest도 임계 경로에 포함된다.
      if (isInside[curr] && dist[curr] - dist[dest] == cost) {
        isInside[dest] = true;
        ++ans;
      }

      --r_indegree[dest];

      if (r_indegree[dest] == 0) {
        que.push(dest);
      }
    }
  }

  cout << ans << '\n';

  return 0;
}