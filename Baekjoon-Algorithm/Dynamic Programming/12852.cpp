/*
==============================+===============================================================
@ Title : 1로 만들기 2
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

int dp[1000001];
int choices[1000001];

int go (int i) {
  if (i < 1) assert(false);
  if (i == 1) return 0;
  int& ans = dp[i];
  if (ans != -1) return ans;
  ans = 2e9;

  if (i % 3 == 0) {
    if (ans > go (i / 3) + 1) {
      ans = go (i / 3) + 1;
      choices[i] = 3;
    }
  }

  if (i % 2 == 0) {
    if (ans > go (i / 2) + 1) {
      ans = go (i / 2) + 1;
      choices[i] = 2;
    }
  }

  if (ans > go (i - 1) + 1) {
    ans = go (i - 1) + 1;
    choices[i] = 1;
  }

  return ans;
}

void reconstruct(int i, vector<int>& ans) {
  ans.push_back(i);
  if (i == 1) {
    return;
  }

  if (choices[i] == 3) {
    reconstruct(i / 3, ans);
  }
  else if (choices[i] == 2) {
    reconstruct(i / 2, ans);
  }
  else {
    reconstruct(i - 1, ans);
  }
}

int solve() {
  _FASTIOS;
  int N;
  cin >> N;
  memset(dp, -1, sizeof dp);
  cout << go(N) << '\n';
  vector<int> ans;
  reconstruct(N, ans);
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << ' ';
  }
  cout << "\n";
  return 0;
}