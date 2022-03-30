/*
==============================+===============================================================
@ Title : 숨바꼭질 5
@ Desc : O(N sqrt N) 시간복잡도를 개선해야 풀 수 있는 문제.
각 칸들은 홀수 시간, 짝수 시간에 방문할 경우 2초 후에 항상 방문 가능하게 되기 때문에,
각 초에서의 상태를 모두 저장하는 게 아니라, 홀수 시간, 짝수 시간에서의 dist 값만 저장하면 풀 수 있다.
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

int dist[500001][2];

int solve() {
  _FASTIOS;
  int N, K;
  cin >> N >> K;
  memset(dist, -1, sizeof dist);

  queue<pii> que;
  que.push({ 0, N });
  dist[N][0] = 0;

  int type, curr;
  while (!que.empty()) {
    tie (type, curr) = que.front(); que.pop();

    for (int next : { curr + 1, curr - 1, curr * 2 }) {
      if (next < 0 || next > 500000) continue;
      if (dist[next][1 - type] != -1) continue;

      dist[next][1 - type] = dist[curr][type] + 1;
      que.push({ 1 - type, next });
    }
  }

  int res = -1;
  int pos = K;

  for (int t = 0;; ++t) {
    pos += t;
    if (pos > 500000) break;
    if (dist[pos][t % 2] <= t) {
      res = t;
      break;
    }
  }

  cout << res << '\n';

  return 0;
}