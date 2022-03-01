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

const int mod = 1000000007;

int N, M, P;
ll dp[101][101];

ll go(int idx, int x) {
  ll& ans = dp[idx][x];
  if (ans != -1) return ans;
  if (idx >= P && x >= N) return 1;
  if (idx >= P) return 0;

  ans = 0;

  // 추가할 수 있는 곡의 갯수가 0보다 커야, 이미 추가 되지 않은 곡의 갯수에서
  // 새로 추가할 곡으로 정할 수 있다.
  if (N - x > 0) {
    ans += go(idx + 1, x + 1) * (N - x);
  }

  // 이미 추가된 곡을 다시 추가하는 경우.
  if (x - M > 0) {
    ans += go(idx + 1, x) * (x - M);
  }

  ans %= mod;

  return ans;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> N >> M >> P;
  memset(dp, -1, sizeof dp);
  cout << go(0, 0) << "\n";
  return 0;
}