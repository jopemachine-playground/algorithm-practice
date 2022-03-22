/*
==============================+===============================================================
@ Title : 플로이드 2
@ Desc : 플로이드 알고리즘의 경로 역추적 문제.
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

int d[101][101];
int nexts[101][101];

const int INF = 1e9;

// 플로이드 알고리즘의 역추적 알고리즘이 꽤 독특한 편이라고 함.
void reconstruct(int x, int y) {
  if (nexts[x][y] == -1) {
    cout << 0 << '\n';
    return;
  }

  queue<int> que;
  que.push(x);
  while (x != y) {
    // next[x][y]에 들렀다가 y로 가도록 변경
    x = nexts[x][y];
    que.push(x);
  }

  cout << que.size() << ' ';
  while (!que.empty()) {
    cout << que.front() << ' ';
    que.pop();
  }

  cout << '\n';
}

int solve() {
  _FASTIOS;
  int V, E;
  cin >> V >> E;

  for (int i = 1; i <= V; ++i) {
    for (int j = 1; j <= V; ++j) {
      if (i != j) {
        d[i][j] = INF;
      }
      else {
        d[i][j] = 0;
      }

      nexts[i][j] = -1;
    }
  }

  for (int i = 0; i < E; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    if (d[from][to] > cost) {
      d[from][to] = cost;
      nexts[from][to] = to;
    }
  }

  for (int k = 1; k <= V; ++k) {
    for (int i = 1; i <= V; ++i) {
      for (int j = 1; j <= V; ++j) {
        if (d[i][j] > d[i][k] + d[k][j]) {
          d[i][j] = d[i][k] + d[k][j];
          // i -> k -> j로 가는 간선을, i -> j로 가는 간선으로 바꿨으니,
          // 원래 가리키고 있던 간선을 저장해준다.
          nexts[i][j] = nexts[i][k];
        }
      }
    }
  }

  for (int i = 1; i <= V; ++i) {
    for (int j = 1; j <= V; ++j) {
      if (d[i][j] != INF) {
        cout << d[i][j] << ' ';
      } else {
        cout << 0 << ' ';
      }
    }
    cout << '\n';
  }

  for (int i = 1; i <= V; ++i) {
    for (int j = 1; j <= V; ++j) {
      if (i == j || d[i][j] == INF) {
        cout << 0 << '\n';
      } else {
        reconstruct(i, j);
      }
    }
  }

  return 0;
}