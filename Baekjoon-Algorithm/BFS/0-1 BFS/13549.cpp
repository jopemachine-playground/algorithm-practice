/*
==============================+===============================================================
@ Title : 숨바꼭질 3
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

int solve() {
  _FASTIOS;

  int N, K;
  cin >> N >> K;
  deque<pii> que;
  vector<bool> visited(100001, false);

  que.push_back({N, 0});

  int top, time = 0;
  while (!que.empty()) {
    tie(top, time) = que.front();
    que.pop_front();

    if (top < 0 || top > 100000) continue;
    if (visited[top]) continue;
    visited[top] = true;

    if (top == K) {
      break;
    } else {
      que.push_front({2 * top, time});
      que.push_back({top + 1, time + 1});
      que.push_back({top - 1, time + 1});
    }
  }

  cout << time;
  return 0;
}
