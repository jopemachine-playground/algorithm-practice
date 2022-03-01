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

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

#define ll long long

// int main() {
int solve() {
  _FASTIOS;
  int N;
  cin >> N;
  vector<int> nums(N);
  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());
  // 가장 큰 약수에 가장 작은 약수를 곱해주면 원래 수를 구할 수 있음.

  cout << ((ll) nums[0]) * nums[nums.size() - 1] << "\n";
  return 0;
}