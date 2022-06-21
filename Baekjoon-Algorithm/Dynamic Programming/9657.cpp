/*
==============================+===============================================================
@ Title : 돌 게임 3
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

bool dp[1001];

int solve() {
  _FASTIOS;

  int N;
  cin >> N;

  dp[1] = true;
  dp[2] = false;
  dp[3] = true;
  dp[4] = true;

  for (int k = 5; k <= N; ++k) {
    dp[k] = !dp[k - 3] || !dp[k - 4] || !dp[k - 1];
  }

  cout << (dp[N] ? "SK" : "CY");

  return 0;
}
