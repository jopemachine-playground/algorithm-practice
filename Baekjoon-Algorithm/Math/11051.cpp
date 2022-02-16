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

int mod = 10007;

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  int dp[1001][1001];
  memset(dp, 0, sizeof dp);

  // 파스칼의 삼각형.
  // 왼쪽과 오른쪽은 1, 그 중간 값들을 계산해주면 된다.
  for (int i = 0; i <= N; ++i) {
    dp[i][0] = dp[i][i] = 1;
    for (int j = 1; j <= i - 1; ++j) {
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
      dp[i][j] %= mod;
    }
  }

  cout << dp[N][K] << "\n";

  return 0;
}