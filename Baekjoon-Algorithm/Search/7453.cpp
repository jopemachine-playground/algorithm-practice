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

vector<int> getPossibleSums(vector<int>& nums1, vector<int>& nums2) {
  vector<int> sums;
  for (int i = 0; i < nums1.size(); ++i) {
    for (int j = 0; j < nums2.size(); ++j) {
      sums.push_back(nums1[i] + nums2[j]);
    }
  }
  return sums;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> a(N), b(N), c(N), d(N);

  for (int i = 0; i < N; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  auto sums1 = getPossibleSums(a, b);
  auto sums2 = getPossibleSums(c, d);

  sort(sums1.begin(), sums1.end());
  sort(sums2.begin(), sums2.end());

  ll ans = 0;
  for (int i = 0; i < sums1.size(); ++i) {
    auto p = equal_range(sums2.begin(), sums2.end(), -sums1[i]);
    ans += p.second - p.first;
  }
  cout << ans << "\n";

  return 0;
}