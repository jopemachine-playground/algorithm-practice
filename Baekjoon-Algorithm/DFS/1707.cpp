/*
==============================+===============================================================
@ Title : 이분 그래프
@ Desc :
@ Ref :
==============================+===============================================================
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <memory.h>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define debug                                                                  \
  if constexpr (LOCAL)                                                         \
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

void dfs(vector<vector<int>> &map, vector<int> &visited, int root, int color) {
  if (visited[root] != -1)
    return;
  visited[root] = color;

  for (int &nextPt : map[root]) {
    dfs(map, visited, nextPt, 1 - color);
  }
}

int solve() {
  _FASTIOS;
  int K;
  cin >> K;
  while (K--) {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> map(V + 1, vector<int>());

    // -1: not visited
    // 0: black
    // 1: white
    vector<int> visited(V + 1, -1);

    while (E--) {
      int u, v;
      cin >> u >> v;
      map[u].push_back(v);
      map[v].push_back(u);
    }

    for (int i = 1; i <= V; ++i) {
      if (visited[i] == -1) {
        dfs(map, visited, i, 0);
      }
    }

    bool isBipartite = true;

    for (int i = 1; i <= V; ++i) {
      if (isBipartite) {
        for (int &linkedPt : map[i]) {
          if (visited[linkedPt] == visited[i]) {
            isBipartite = false;
            break;
          }
        }
      }
    }

    if (isBipartite) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
