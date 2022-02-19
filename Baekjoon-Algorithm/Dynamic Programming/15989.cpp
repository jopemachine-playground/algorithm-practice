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
#define endl '\n'

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;

  vector<int> dp(10001, 0);
  dp[0] = 1;
  dp[1] = 1;

  for (int j = 1; j <= 3; ++j) {
    for (int i = 2; i <= 10000; ++i) {
      dp[i] += dp[i - j];
    }
  }

  for (int i = 0; i < T; ++i) {
    int k;
    cin >> k;
    cout << dp[k] << "\n";
  }

  return 0;
}