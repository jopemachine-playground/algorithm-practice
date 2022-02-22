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

vector<int> getPartialSums(vector<int>& nums) {
  vector<int> partialSums(nums.size(), 0);
  int sum = 0;
  for (int i = 0; i < nums.size(); ++i) {
    sum += nums[i];
    partialSums[i] = sum;
  }
  return partialSums;
}

int getPrefixSum(vector<int>& partialSums, int start, int end) {
  if (start == 0) return partialSums[end];
  return partialSums[end] - partialSums[start - 1];
}

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

  // 2N 개가 될 때 까지 복사
  for (int i = 0; i < N; ++i) {
    nums.push_back(nums[i]);
  }

  auto partialSums = getPartialSums(nums);

  int maxVal = -1;
  for (int i = 0; i < N; ++i) {
    maxVal = max(maxVal, getPrefixSum(partialSums, i, i + K - 1));
  }

  cout << maxVal << "\n";

  return 0;
}