/*
==============================+===============================================================
@ Title : 최소비용 구하기 2
@ Desc : 스택, 배열을 이용한 풀이
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
  Edge(int to, int cost): to(to), cost(cost) {};
};

int dist[1001];
bool visited[1001];
int froms[1001];
vector<Edge> graph[1001];
const int INF = 1e9;

int solve() {
  _FASTIOS;
  int V, E;
  cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    graph[from].push_back(Edge(to, cost));
  }

  int start, end;
  cin >> start >> end;
  for (int i = 1; i <= V; ++i) {
    dist[i] = INF;
  }

  dist[start] = 0;
  froms[start] = -1;

  for (int k = 0; k < V - 1; ++k) {
    int cost = INF + 1;
    int dest = -1;
    for (int i = 1; i <= V; ++i) {
      if (!visited[i] && cost > dist[i]) {
        cost = dist[i];
        dest = i;
      }
    }
    if (dest == -1) continue;
    visited[dest] = true;

    vector<Edge>& linkedList = graph[dest];
    for (int i = 0; i < linkedList.size(); ++i) {
      int to = linkedList[i].to;
      if (dist[to] > dist[dest] + linkedList[i].cost) {
        dist[to] = dist[dest] + linkedList[i].cost;
        froms[to] = dest;
      }
    }
  }

  cout << dist[end] << '\n';

  stack<int> stk;
  int x = end;
  while (x != -1) {
    stk.push(x);
    x = froms[x];
  }

  cout << stk.size() << '\n';

  while (!stk.empty()) {
    cout << stk.top() << ' ';
    stk.pop();
  }
  cout << '\n';

  return 0;
}