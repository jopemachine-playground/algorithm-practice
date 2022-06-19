/*
==============================+===============================================================
@ Title : 우주신과의 교감
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
#define pii pair<ll, ll>

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

struct Edge {
  int to;
  long double cost;
  bool operator < (const Edge& rhs) const {
    return cost > rhs.cost;
  }
};

vector<Edge> graph[1001];

bool visited[1001];

long double getSquareDist(ll x1, ll y1, ll x2, ll y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int solve() {
  _FASTIOS;

  int N, M;
  cin >> N >> M;
  vector<pii> cords(N);
  for (auto& cord : cords) {
    cin >> cord.first >> cord.second;
  }

  vector<pii> connected(M);
  for (auto& connectedPt : connected) {
    cin >> connectedPt.first >> connectedPt.second;
  }

  sort(connected.begin(), connected.end());

  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      if (i == j) continue;

      if (
        (find(connected.begin(), connected.end(), make_pair(i + 1, j + 1)) != connected.end()) ||
        (find(connected.begin(), connected.end(), make_pair(j + 1, i + 1)) != connected.end())
      ) {
        graph[i].push_back(Edge {(int) j, 0});
      } else {
        graph[i].push_back(Edge {(int) j, getSquareDist(cords[i].first, cords[i].second, cords[j].first, cords[j].second)});
      }
   }
  }

  visited[0] = true;
  priority_queue<Edge> pque;

  for (auto edge : graph[0]) {
    pque.push(edge);
  }

  long double ans = 0.0;

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

  cout << fixed;
  cout.precision(2);
  cout << ans;
  return 0;
}
