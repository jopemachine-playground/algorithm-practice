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

char prev(char ch) {
  if (ch == 'B') return 'J';
  if (ch == 'O') return 'B';
  if (ch == 'J') return 'O';
  return ' ';
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  string map;
  cin >> map;
  
  vector<int> dp(N, -1);
  dp[0] = 0;

  for (int i = 0; i < N; ++i) {
    // 이전 블록을 k라 하면..
    for (int k = 0; k < i; ++k) {
      if (dp[k] == -1) continue;
      if (prev(map[i]) != map[k]) continue;

      int cost = dp[k] + (i - k) * (i - k);
      if (dp[i] == -1 || dp[i] > cost) {
        dp[i] = cost;
      }
    }
  }

  cout << dp[N - 1] << "\n";

  return 0;
}