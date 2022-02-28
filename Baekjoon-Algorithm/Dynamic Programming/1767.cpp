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

ll dp[101][101][101];

const int mod = 1000001;

ll calc(int r, int c, int k) {
  // Base case : 세 줘야 하는 케이스
  if (k == 0) return 1;
  // Base case : 세지 말아야 하는 케이스
  if (r <= 0 || c <= 0 || k < 0) return 0;

  ll& ans = dp[r][c][k];
  if (ans != -1) return ans;
  ans = 0;

  ans += calc(r - 1, c, k);
  ans += calc(r - 1, c - 1, k - 1) * c;
  ans += calc(r - 1, c - 2, k - 2) * (c * (c - 1) / 2);
  ans += calc(r - 2, c - 1, k - 2) * (r - 1) * c;

  ans %= mod;

  return ans;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N, M, K;
  cin >> N >> M >> K;

  memset(dp, -1, sizeof dp);

  cout << calc(N, M, K) << "\n";

  return 0;
}