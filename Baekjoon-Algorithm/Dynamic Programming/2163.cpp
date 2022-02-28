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

int N, M;
// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> N >> M;
  vector<vector<int>> dp(N + 1, vector<int>(M + 1, 987654321));
  dp[1][1] = 0;

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      // 가로로 쪼개는 경우
      for (int k = 1; k < i; ++k) {
        dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
      }
      // 세로로 쪼개는 경우
      for (int k = 1; k < j; ++k) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
      }
    }
  }

  cout << dp[N][M] << "\n";

  return 0;
}