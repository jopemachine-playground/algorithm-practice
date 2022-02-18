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

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto& i : A) {
    cin >> i;
  }

  vector<int> dp(N, -1);
  dp[0] = 0;

  for (int i = 0; i < N - 1; ++i) {
    if (dp[i] == -1) continue;
    for (int j = 1; j <= A[i]; ++j) {
      if (i + j >= N) {
        break;
      }

      if (dp[i + j] == -1 || dp[i + j] > dp[i] + 1) {
        dp[i + j] = dp[i] + 1;
      }
    }
  }

  cout << dp[N - 1] << "\n";

  return 0;
}