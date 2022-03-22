/*
==============================+===============================================================
@ Title : 케빈 베이컨의 6단계 법칙
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

int d[101][101];

const int INF = 1e9;

int solve() {
  _FASTIOS;
  int V, E;
  cin >> V >> E;

  for (int i = 1; i <= V; ++i) {
    for (int j = 1; j <= V; ++j) {
      if (i == j) d[i][j] = 0;
      else d[i][j] = INF;
    }
  }

  for (int i = 0; i < E; ++i) {
    int from, to;
    cin >> from >> to;
    d[from][to] = d[to][from] = 1;
  }

  for (int k = 1; k <= V; ++k) {
    for (int i = 1; i <= V; ++i) {
      for (int j = 1; j <= V; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int who = -1;
  int minVal = 1e9;
  for (int i = 1; i <= V; ++i) {
    int sum = 0;
    for (int j = 1; j <= V; ++j) {
      if (i != j) {
        sum += d[i][j];
      }
    }

    if (minVal > sum) {
      minVal = sum;
      who = i;
    }
  }

  cout << who << '\n';

  return 0;
}