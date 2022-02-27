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

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  // 선조건: M은 소수
  ll N, K, M;
  cin >> N >> K >> M;

  // 이항 정리 값을 M 높이까지만 계산할 것이니
  // 크기는 M + 1까지 잡으면 된다.
  vector<vector<int>> dp(M + 1, vector<int>(M + 1));

  // 루카스 정리 적용을 위해 우선, 파스칼의 삼각형을 만들고 값 계산.
  for (int i = 0; i <= M; ++i) {
    dp[i][0] = dp[i][i] = 1;
    for (int j = 1; j <= i - 1; ++j) {
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      dp[i][j] %= M;
    }
  }

  // 루카스의 정리를 위해 N, K를 각각 M진법으로 나타낸다.
  // 아래 a, b에 M진법으로 나타내었을 때의 계수들을 배열로 저장한다.
  vector<int> a, b;
  while (N > 0 || K > 0) {
    a.push_back(N % M);
    b.push_back(K % M);
    N /= M;
    K /= M;
  }

  ll ans = 1;

  // 루카스 정리 적용해 이항계수 계산.
  for (int i = 0; i < a.size(); ++i) {
    ans *= dp[a[i]][b[i]];
    ans %= M;
  }

  cout << ans << "\n";

  return 0;
}