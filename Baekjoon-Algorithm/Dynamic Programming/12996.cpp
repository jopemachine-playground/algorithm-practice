// 백준 알고리즘 중급
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

ll dp[51][51][51][51];

ll go(int idx, int a, int b, int c) {
  if (a < 0 || b < 0 || c < 0) return 0;
  if (idx == 0) {
    // 모든 곡을 돈 시점에서 a, b, c를 다 썼다면 경우의 수를 하나 센다.
    return (a + b + c == 0 ? 1 : 0);
  }

  ll& ans = dp[idx][a][b][c];
  if (ans != -1) return ans;
  ans = 0;

  for (int da = 0; da < 2; ++da) {
    for (int db = 0; db < 2; ++db) {
      for (int dc = 0; dc < 2; ++dc) {
        if (da + db + dc == 0) continue;
        ans += go(idx - 1, a - da, b - db, c - dc);
        ans %= mod;
      }
    }
  }

  return ans;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N, A, B, C;
  cin >> N >> A >> B >> C;

  memset(dp, -1, sizeof(dp));

  cout << go(N, A, B, C) << "\n";

  return 0;
}