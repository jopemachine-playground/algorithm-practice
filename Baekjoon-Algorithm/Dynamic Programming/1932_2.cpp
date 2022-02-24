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

int dp[501][501];

int go(vector<vector<int>>& map, int i, int j) {
  if (i < 0 || j >= map[i].size()) return -1e9;

  int& ans = dp[i][j];
  if (ans != -1) return ans;

  ans = max(go(map, i - 1, j), go(map, i - 1, j - 1)) + map[i][j];
  return ans;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<vector<int>> map;
  memset(dp, -1, sizeof(dp));

  for (int i = 1; i <= N; ++i) {
    vector<int> row(i);
    for (int j = 0; j < i; ++j) {
      cin >> row[j];
    }
    map.push_back(row);
  }

  dp[0][0] = map[0][0];

  int ans = -1e9;
  for (int i = 0; i < N; ++i) {
    ans = max(ans, go(map, N - 1, i));
  }

  cout << ans << "\n";

  return 0;
}