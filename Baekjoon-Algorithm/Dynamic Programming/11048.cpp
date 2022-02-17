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

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;

  vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      cin >> dp[i][j];
    }
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      int cands[3] = { dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] };
      int max = *max_element(cands, cands + 3);
      dp[i][j] += max;
    }
  }

  cout << dp[N][M] << '\n';

  return 0;
}