/*
==============================+===============================================================
@ Title : 전깃줄
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

int dp[101];

int go (vector<pii>& lines, int k) {
  int& ans = dp[k];
  if (ans != -1) return ans;
  if (k >= lines.size()) return 1;

  ans = 1;

  for (int i = k + 1; i < lines.size(); ++i) {
    if (lines[k].second < lines[i].second) {
      ans = max(ans, go(lines, i) + 1);
    }
  }

  return ans;
}

int solve() {
  _FASTIOS;

  int N;
  cin >> N;
  vector<pii> lines(N);

  for (pii& line : lines) {
    cin >> line.first >> line.second;
  }

  lines.push_back({ -2e9, -2e9 });

  sort(lines.begin(), lines.end());

  memset(dp, -1, sizeof(dp));

  cout << N - (go (lines, 0) - 1);

  return 0;
}
