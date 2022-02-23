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

#define ll long long

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<vector<int>> map(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> map[i][j];
    }
  }

  vector<vector<ll>> dp(N, vector<ll>(N, 0));
  dp[0][0] = 1;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < j; ++k) {
        if (map[i][k] + k == j) {
          dp[i][j] += dp[i][k];
        }
      }

      for (int k = 0; k < i; ++k) {
        if (map[k][j] + k == i) {
          dp[i][j] += dp[k][j];
        }
      }
    }
  }

  cout << dp[N - 1][N - 1] << "\n";

  return 0;
}