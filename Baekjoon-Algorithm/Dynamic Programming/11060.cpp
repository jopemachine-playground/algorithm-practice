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

  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      if (dp[j] != -1 && i - j <= A[j]) {
        if (dp[i] == -1 || dp[i] > dp[j] + 1) {
          dp[i] = dp[j] + 1;
        }
      }
    }
  }

  // for (int i = 0; i < N; ++i) {
  //   cout << dp[i] << " ";
  // }
  cout << dp[N - 1] << "\n";

  return 0;
}