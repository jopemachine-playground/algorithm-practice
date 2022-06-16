/*
==============================+===============================================================
@ Title : 별자리 만들기
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
  double cost;
  bool operator < (const Edge& rhs) const {
    return cost > rhs.cost;
  }
};

vector<Edge> graph[101];

bool visited[101];

double getSquareDist(double x1, double y1, double x2, double y2) {
  return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

int solve() {
  _FASTIOS;

  int N;
  cin >> N;

  vector<pair<double, double>> cords;
  for (int i = 0; i < N; ++i) {
    double x, y;
    cin >> x >> y;
    cords.push_back({x, y});
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i == j) continue;
      graph[i].push_back(Edge {j, getSquareDist(cords[i].first, cords[i].second, cords[j].first, cords[j].second)});
    }
  }

  visited[0] = true;

  priority_queue<Edge> pque;

  for (Edge edge : graph[0]) {
    pque.push(edge);
  }

  double ans = 0;

  while (!pque.empty()) {
    Edge edge = pque.top();
    pque.pop();
    if (visited[edge.to]) continue;
    visited[edge.to] = true;
    ans += sqrt(edge.cost);

    for (Edge nextEdge : graph[edge.to]) {
      pque.push(nextEdge);
    }
  }

  cout.precision(3);
  cout << ans;
  return 0;
}
