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
int nums[50001];
int sums[50001];
int dp[50001][4];

int getRangeSum(int left, int right) {
  return sums[right] - sums[left - 1];
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N;

  int sum = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> nums[i];
    sum += nums[i];
    sums[i] = sum;
  }

  cin >> M;

  // i를 0 부터 N까지 계산하고 i - M이 0 보다 크거나 같을 때만 계산해도 되지만..
  // 애초에 i가 M 보다 작지 않도록 넣어줘도 무방.
  // 어차피 i가 M 보다 작은 경우 소형기관차가 어떤 객차도 끌 수 없게 되어버리기 때문.
  for (int i = M; i <= N; ++i) {
    for (int j = 1; j <= 3; ++j) {
      dp[i][j] = max(dp[i - 1][j], dp[i - M][j - 1] + getRangeSum(i - M + 1, i));
    }
  }

  cout << dp[N][3] << "\n";

  return 0;
}