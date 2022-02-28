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
  int N = 5;
  vector<int> nums(N);
  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
  }
  int squareSum = 0;
  for (auto num : nums) {
    squareSum += num * num;
  }
  cout << squareSum % 10 << "\n";
  return 0;
}