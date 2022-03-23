/*
==============================+===============================================================
@ Title : LCA 2
@ Desc : DP로 lgN에 LCA 구하기
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

const int MAX = 100001;

vector<int> graph[MAX];
bool visited[MAX];
int depth[MAX];
int parents[MAX];
// 2^17이면 10만 보다 크기 때문에 17이면 충분함.
int dp[MAX][17];

// 트리를 lg로 올라가서 O(lgN)에 LCA를 구하는 dp 알고리즘.
int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }

  // 최대 높이를 구하고..
  int log = 1;
  while ((1 << log) <= depth[u]) ++log;
  --log;

  // 두 노드의 레벨이 같아질 때 까지 
  // (u가 v를 넘어가버리지 않게) 2^i 만큼 위로 증가시키자.
  for (int i = log; i >= 0; --i) {
    if (depth[u] - (1 << i) >= depth[v]) {
      u = dp[u][i];
    }
  }

  // v가 u의 조상인 경우
  if (u == v) return u;

  // u, v의 높이가 같아졌으니 서로 같이 2^i 만큼 위로 올라가면서 LCA를 찾는다.
  for (int i = log; i >= 0; --i) {
    // dp[u][i]가 0인 경우 -> 조상이 없으므로 넘어감.
    // (존재하는) u, v의 조상이 서로 다를 경우에만 올라감.
    if (dp[u][i] != 0 && dp[u][i] != dp[v][i]) {
      u = dp[u][i];
      v = dp[v][i];
    }
  }

  return parents[u];
}

int solve() {
  _FASTIOS;
  int N;
  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  depth[1] = 0;
  visited[1] = true;
  queue<int> que;
  que.push(1);
  parents[1] = 0;

  // BFS로 부모 찾고, depth 저장.
  while (!que.empty()) {
    int curr = que.front(); que.pop();
    vector<int>& linkedList = graph[curr];
    for (int to : linkedList) {
      if (!visited[to]) {
        depth[to] = depth[curr] + 1;
        visited[to] = true;
        parents[to] = curr;
        que.push(to);
      }
    }
  }

  // Base case : 2^0 번째 조상은 부모.
  for (int i = 1; i <= N ; ++i) {
    dp[i][0] = parents[i];
  }

  // dp 테이블을 채운다.
  // 점화식: i의 2^j 번째 조상은 dp[i][2^j-1] 번째 조상의 2 ^j - 1번째 조상이다.
  for (int j = 1; (1 << j) < N; ++j) {
    for (int i = 1; i <= N; ++i) {
      // dp[i][j - 1]가 0인 경우 : 조상이 없는 경우
      if (dp[i][j - 1] != 0) {
        dp[i][j] = dp[dp[i][j - 1]][j - 1];
      }
    }
  }

  int M;
  cin >> M;
  while (M--) {
    int u, v;
    cin >> u >> v;
    cout << lca(u, v) << '\n';
  }

  return 0;
}