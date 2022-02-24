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

int dp[1001];

int go (vector<int>& nums, int idx) {
  int& ans = dp[idx];
  if (ans != -1) return ans;
  if (idx >= nums.size()) return 1;

  ans = 1;
  for (int i = idx + 1; i < nums.size(); ++i) {
    if (nums[idx] < nums[i]) {
      ans = max(ans, go(nums, i) + 1);
    }
  }

  return ans;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  memset(dp, -1, sizeof(dp));

  vector<int> nums(N + 1);
  nums[0] = -2e9;

  for (int i = 1; i <= N; ++i) {
    cin >> nums[i];
  }

  cout << go(nums, 0) - 1 << "\n";

  return 0;
}