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

ll dp[101][21];

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> nums(N);
  for (auto& i : nums) {
    cin >> i;
  }
  int goal = nums[nums.size() - 1];
  nums.pop_back();

  dp[0][nums[0]] = 1;

  for (int i = 1; i < N; ++i) {
    for (int j = 0; j <= 20; ++j) {
      if (j - nums[i] >= 0) {
        dp[i][j] += dp[i - 1][j - nums[i]];
      }
      if (j + nums[i] <= 20) {
        dp[i][j] += dp[i - 1][j + nums[i]];
      }
    }
  }

  cout << dp[nums.size() - 1][goal] << "\n";

  return 0;
}