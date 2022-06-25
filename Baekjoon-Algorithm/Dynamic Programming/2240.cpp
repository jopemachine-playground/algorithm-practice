/*
==============================+===============================================================
@ Title : 자두나무
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

int T, W;

int fruitPos[1001];

int dp[1001][2][31];

int go(int time, int pos, int moveCnt) {
  if (time > T || moveCnt > W)
    return 0;

  int &ans = dp[time][pos][moveCnt];
  if (ans != -1) {
    return ans;
  }

  ans = max(go(time + 1, 1 - pos, moveCnt + 1), go(time + 1, pos, moveCnt));

  if (fruitPos[time] == pos) {
    ++ans;
  }

  return ans;
}

int solve() {
  _FASTIOS;

  cin >> T >> W;

  memset(dp, -1, sizeof dp);
  memset(fruitPos, -1, sizeof fruitPos);

  for (int i = 1; i <= T; ++i) {
    int pos;
    cin >> pos;
    fruitPos[i] = pos - 1;
  }

  cout << go(0, 0, 0);

  return 0;
}
