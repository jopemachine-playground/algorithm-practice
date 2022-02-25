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

const ll mod = 1000000007LL;

long long dp[5001];

ll go(int len) {
  // len이 0에 도달했으면 경우의 수를 하나 더해준다.
  if (len == 0) return 1;

  ll& ans = dp[len];
  if (ans != -1) return ans;
  ans = 0;

  for (int k = 2; k <= len; k += 2) {
    ans += go(len - k) * go(k - 2);
    ans %= mod;
  }

  return ans;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) {
    int L;
    cin >> L;
    memset(dp, -1, sizeof(dp));

    if (L % 2 == 1) {
      cout << 0 << "\n";
    } else {
      cout << go(L) << "\n";
    }
  }

  return 0;
}