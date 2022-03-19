/*
==============================+===============================================================
@ Title : 최소비용 구하기
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

vector<Edge> graphs[20001];

int dist[20001];
bool visited[20001];
int INF = 1e9;

int solve() {
  _FASTIOS;
  int N, M;
  cin >> N >> M;
  int start;
  cin >> start;
  
  for (int i = 0; i < M; ++i) {
    int A, B, C;
    cin >> A >> B >> C;
    graphs[A].push_back(Edge(B, C));
  }

  for (int i = 1; i <= N; ++i) {
    dist[i] = INF;
  }

  dist[start] = 0;

  priority_queue<pii> pQue;
  pQue.push({ 0, start });
  int cost, dest;

  while (!pQue.empty()) {
    tie(cost, dest) = pQue.top();
    pQue.pop();
    if (visited[dest]) continue;
    visited[dest] = true;

    vector<Edge>& linkedList = graphs[dest];

    for (int i = 0; i < linkedList.size(); ++i) {
      int to = linkedList[i].to;
      if (dist[to] > dist[dest] + linkedList[i].cost) {
        dist[to] = dist[dest] + linkedList[i].cost;
        pQue.push({ -dist[to], to });
      }
    }
  }

  for (int i = 1; i <= N; ++i) {
    if (dist[i] >= INF) {
      cout << "INF\n";
    }
    else {
      cout << dist[i] << "\n";
    }
  }
  
  return 0;
}