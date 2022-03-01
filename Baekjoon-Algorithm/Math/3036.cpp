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

int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}

// int main() {
int solve() {
  _FASTIOS;
  int N;
  cin >> N;
  vector<int> nums(N);
  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
  }

  for (int i = 1; i < N; ++i) {
    int gcdValue = gcd(nums[i], nums[0]);
    cout << (nums[0] / gcdValue) << "/" << (nums[i] / gcdValue) << "\n";
  }

  return 0;
}