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

  // K를 만들 수 있는 방법의 갯수.
  vector<int> dp(K + 1, 0);

  // 0을 만들 수 있는 방법의 갯수는 0만 있는 경우로 1개.
  dp[0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int j = 1; j <= K; ++j) {
      if (j - nums[i] >= 0) {
        dp[j] += dp[j - nums[i]];
      }
    }
  }

  cout << dp[K] << "\n";

  return 0;
}