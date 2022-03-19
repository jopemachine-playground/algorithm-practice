/*
==============================+===============================================================
@ Title : LCA
@ Desc :
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

const int MAX = 50001;

vector<int> graph[MAX];
bool visited[MAX];
int depth[MAX];
int parents[MAX];

// O(N)으로 LCA를 구하는 가장 기본적인 알고리즘
// 더 깊이가 깊은 정점을 위쪽으로 올리고, LCA를 찾을 때 까지 두 개를 같이 올림.
int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }

  while (depth[u] != depth[v]) {
    u = parents[u];
  }

  while (u != v) {
    u = parents[u];
    v = parents[v];
  }

  return u;
}

int solve() {
  _FASTIOS;
  int N;
  cin >> N;

  for (int i = 0; i < N - 1; ++i) {
    int A, B;
    cin >> A >> B;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }

  depth[1] = 0;
  visited[1] = true;
  queue<int> que;
  que.push(1);
  parents[1] = 0;

  // LCA 알고리즘을 사용하기 위해 
  // BFS를 돌면서 parents들을 모두 체크하고, depth를 구해주자.
  while (!que.empty()) {
    int curr = que.front();
    que.pop();
    for (int next : graph[curr]) {
      if (!visited[next]) {
        visited[next] = true;
        depth[next] = depth[curr] + 1;
        parents[next] = curr;
        que.push(next);
      }
    }
  }

  int M;
  cin >> M;
  while (M--) {
    int A, B;
    cin >> A >> B;
    cout << lca(A, B) << '\n';
  }

  return 0;
}