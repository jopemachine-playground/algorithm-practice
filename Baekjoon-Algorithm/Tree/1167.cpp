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

vector<pii> tree[100001];

int answers[100001];
bool visited[100001];

int maxWeight;
int maxDest;

// Ref: https://donggoolosori.github.io/2020/10/12/boj-1167/
// pii를 리턴 값으로 하려다 꼬였다;
// 두 개 이상 리턴 값이면 전역으로 빼고 인자 하나 더 넣는 것도 좋은 방법인 듯..
void dfs(int node, int weightSum) {
  if (visited[node]) return;
  visited[node] = true;

  vector<pii>& childs = tree[node];

  if (maxWeight < weightSum) {
    maxWeight = weightSum;
    maxDest = node;
  }

  int dest, weight;

  for (auto it = childs.begin(); it != childs.end(); ++it) {
    tie(dest, weight) = (*it);
    dfs(dest, weightSum + weight);
  }
}

int solve() {
  _FASTIOS;
  int N;
  cin >> N;

  for (int i = 1; i <= N; ++i) {
    int idx;
    cin >> idx;

    while (true) {
      int dest, weight;
      cin >> dest;
      if (dest == -1) break;
      cin >> weight;

      tree[idx].push_back({ dest, weight });
      tree[dest].push_back({ idx, weight });
    }
  }

  // 임의의 점을 하나 고르고 (x), 그 점에서 가장 먼 거리의 점을 y라 한다.
  // y에서 가장 먼 거리의 점 (z) 까지의 거리가 트리의 지름이 된다.
  // 증명 Ref: https://blog.myungwoo.kr/112
  int x, y, z;
  x = 1;
  dfs(x, 0);
  y = maxDest;

  memset(visited, 0, sizeof visited);

  dfs(y, 0);

  cout << maxWeight << "\n";

  return 0;
}