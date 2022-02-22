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
  int N, K;
  cin >> N >> K;
  vector<int> nums(N);
  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
  }

  vector<int> dp(K + 1, -1);
  dp[0] = 0;

  for (int i = 0; i < N; ++i) {
    for (int j = 1; j <= K; ++j) {
      int minVal = dp[j] == -1 ? 2000000000 : dp[j];

      if (
        j - nums[i] >= 0 && 
        dp[j - nums[i]] != -1
      ) {
        dp[j] = min(minVal, dp[j - nums[i]] + 1);
      }
    }
  }

  cout << dp[K] << "\n";

  return 0;
}