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
  int N, S, M;
  cin >> N >> S >> M;

  // 0번째 연주에서 시작해서 N번째 연주까지 가기 때문에 반복문이 N + 1번 반복해야 함에 주의
  // (1번째 부터 시작이 아님!)
  vector<int> diffs(N + 1, 0);
  for (int i = 1; i <= N; ++i) {
    cin >> diffs[i];
  }

  // i번째 연주에서 볼륨 M으로 연주하는 것이 가능한 지?
  vector<vector<bool>> dp(N + 1, vector<bool>(M, false));
  dp[0][S] = true;
  for (int i = 0; i + 1 <= N; ++i) {
    for (int j = 0; j <= M; ++j) {
      // i번째 연주에서 볼륨 j으로 연주하는 게 가능하다면,
      if (dp[i][j]) {
        if (j + diffs[i + 1] <= M) {
          dp[i + 1][j + diffs[i + 1]] = true;
        }
        if (j - diffs[i + 1] >= 0) {
          dp[i + 1][j - diffs[i + 1]] = true;
        }
      }
    }
  }

  int max = -1;

  for (int i = 0; i <= M; ++i) {
    if (dp[N][i]) {
      max = i;
    }
  }

  cout << max << "\n";

  return 0;
}