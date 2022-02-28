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

const long long mod = 1000000007LL;

long long dp[5001][5001];

// 길이가 N이고, 안 맞는 여는 괄호의 갯수가 L인 올바른 괄호 문자열의 갯수
long long getCnt(int n, int l) {
  long long& ans = dp[n][l];
  if (ans >= 0) return ans;

  // Base case
  if (n == 0 && l == 0) return 1;
  if (n == 0) return 0;

  long long res = 0;

  if (l + 1 <= n) {
    res += getCnt(n - 1, l + 1);
  }
  // 안 맞는 여는 괄호의 수가 음수 = 닫는 괄호가 더 많음 => 절대 올바른 괄호 문자열이 될 수 없다.
  if (l - 1 >= 0) {
    res += getCnt (n - 1, l - 1);
  }

  res %= mod;

  ans = res;

  return ans;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  memset(dp, -1, sizeof(dp));
  while(T--) {
    int L;
    cin >> L;
    cout << getCnt(L, 0) << "\n";
  }

  return 0;
}