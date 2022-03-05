// 백준 알고리즘 중급
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

  while (true) {
    int N;
    cin >> N;
    if (N == 0) break;

    vector<ll> heights(N);
    for (int i = 0; i < N; ++i) {
      cin >> heights[i];
    }

    ll maxArea = 0;
    stack<ll> stk;

    for (int i = 0; i < N; ++i) {
      // 높이가 낮아지면 가능한 모든 넓이 계산
      while (!stk.empty() && heights[stk.top()] > heights[i]) {
        ll h = heights[stk.top()];
        stk.pop();
        ll w = stk.empty() ? i : i - stk.top() - 1;
        maxArea = max(maxArea, h * w);
      }

      stk.push(i);
    }

    while(!stk.empty()) {
      ll h = heights[stk.top()];
      stk.pop();
      ll w = stk.empty() ? N : N - stk.top() - 1;
      maxArea = max(maxArea, h * w);
    }

    cout << maxArea << '\n';
  }

  return 0;
}