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

ll dp[21][21];

// 최대 공약수를 찾아 나눠주자.
ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> N >> M;

  // 전체 경우의 수. 순열. (N!)
  ll all = 1;
  for (int i = 2; i <= N; ++i) {
    all *= i;
  }

  // Base case: 모든 상자가 열렸을 때, 경우의 수를 세 준다.
  // => 사실 문제의 조건에서 N, M이 1보다 크거나 같기 때문에 dp[1][1]만 1로 해 줘도 됨
  for (int i = 0; i <= M; ++i) {
    dp[0][i] = 1;
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      dp[i][j] = dp[i - 1][j - 1] + (i - 1) * dp[i - 1][j];
    }
  }

  ll gc = gcd(dp[N][M], all);

  cout << (dp[N][M] / gc) << "/" << (all / gc) << "\n";

  return 0;
}