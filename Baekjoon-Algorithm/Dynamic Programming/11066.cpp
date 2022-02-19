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

int query(vector<int>& nums, vector<vector<int>>& dp, int start, int end) {
  if (start >= end) return 0;

  int& ans = dp[start][end];

  if (ans != 2000000000) {
    return ans;
  }

  int partialSum = 0;
  for (int k = start; k <= end; ++k) {
    partialSum += nums[k];
  }

  for (int k = start; k < end; ++k) {
    ans = min(
      query(nums, dp, start, k) + query(nums, dp, k + 1, end) + partialSum,
      ans
    );
  }

  debug << "start: " << start << "\n";
  debug << "end: " << end << "\n";
  debug << ans << "\n";
  debug << "-----------------------" << "\n";

  return ans;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int K;
    cin >> K;
    vector<int> nums(K);
    for (auto& i : nums) {
      cin >> i;
      // debug << i << "\n";
    }
    vector<vector<int>> dp(K, vector<int>(K, 2000000000));
    cout << query(nums, dp, 0, K - 1) << "\n";
  }

  return 0;
}