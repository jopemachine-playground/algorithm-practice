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

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  // 걸리는 시간, 금액
  vector<pair<int, int>> data(N);
  // OutOfBound 에러를 피하기 위해 T의 최댓값만큼 더해줘야 함에 주의할 것.
  // 물론 최대 길이가 1000이니 1050으로 고정해써도 됨.
  vector<int> dp(N + 50, 0);

  for (int i = 0; i < N; ++i) {
    cin >> data[i].first >> data[i].second;
    // 상담을 안 하는 경우
    dp[i + 1] = max(dp[i], dp[i + 1]);
    // 상담을 하는 경우
    dp[i + data[i].first] = max(dp[i + data[i].first], dp[i] + data[i].second);
  }

  cout << dp[N] << "\n";

  return 0;
}