/*
==============================+===============================================================
@ Title : 두 가중치
@ Desc : 정점의 정의에 한 가중치를 포함시킨 후 다익스트라를 돌리면 된다.
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

int w1[21][21];
int w2[21][21];
int d[21][21 * 9];
bool visited[21][21 * 9];

const int INF = 1e9;

int solve() {
  _FASTIOS;
  int N;
  cin >> N;
  
  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    assert(str.length() == N);

    for (int j = 0; j < N; ++j) {
      if (str[j] != '.') {
        w1[i][j] = (str[j] - '0');
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    assert(str.length() == N);

    for (int j = 0; j < N; ++j) {
      if (str[j] != '.') {
        w2[i][j] = (str[j] - '0');
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= N * 9; ++j) {
      d[i][j] = INF;
    }
  }

  d[0][0] = 0;
  priority_queue<tuple<int, int, int>> pq;
  pq.push(make_tuple(0, 0, 0));

  int cost, curr, w2Dist;
  while (!pq.empty()) {
    tie(cost, curr, w2Dist) = pq.top(); pq.pop();
    if (visited[curr][w2Dist]) continue;
    visited[curr][w2Dist] = true;

    for (int i = 0; i < N; ++i) {
      int dest = i;
      if (w1[curr][dest] == 0) continue;
      int d1 = d[curr][w2Dist] + w1[curr][dest];
      int d2 = w2Dist + w2[curr][dest];
      if (d2 >= N * 9) continue;

      if (d[dest][d2] > d1) {
        d[dest][d2] = d1;
        pq.push(make_tuple(-d[dest][d2], dest, d2));
      }
    }
  }

  int ans = INF;
  for (int i = 0; i <= N * 9; ++i) {
    if (!visited[1][i]) continue;
    ans = min(ans, d[1][i] * i);
  }
  if (ans == INF) ans = -1;
  cout << ans << '\n';

  return 0;
}