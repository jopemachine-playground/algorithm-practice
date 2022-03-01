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

int brands[1001];
int dp[1001][1001];

int go(int i, int j) {
  int& ans = dp[i][j];
  if (i >= j) return ans = 0;
  if (ans != -1) return ans;

  // i랑 이어지는 k가 없는 경우
  ans = go(i + 1, j);

  for (int k = i + 1; k <= j; ++k) {
    if (brands[i] == brands[k]) {
      ans = max(ans, go(i + 1, k - 1) + go(k + 1, j) + 1);
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
  for (int i = 0; i < N; ++i) {
    cin >> brands[i];
  }

  memset(dp, -1, sizeof dp);

  cout << go(0, N - 1) << "\n";

  return 0;
}