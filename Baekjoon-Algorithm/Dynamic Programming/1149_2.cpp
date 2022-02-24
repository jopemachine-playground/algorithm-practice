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

int dp[1001][3];

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<array<int, 3>> costs(N);

  for (auto& cost : costs) {
    cin >> cost[0] >> cost[1] >> cost[2];
  }

  dp[0][0] = costs[0][0];
  dp[0][1] = costs[0][1];
  dp[0][2] = costs[0][2];

  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < 3; ++j) {
      int cost = costs[i][j];

      if (j == 0) {
        dp[i][j] = min(dp[i - 1][1], dp[i - 1][2]);
      }
      else if (j == 1) {
        dp[i][j] = min(dp[i - 1][2], dp[i - 1][0]);
      }
      else if (j == 2) {
        dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]);
      }

      dp[i][j] += cost;
    }
  }

  cout << *min_element(dp[N], dp[N] + 3) << "\n";

  return 0;
}