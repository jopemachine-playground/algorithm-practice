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

int N;

pair<int,int> matrixes[501];

int dp[501][501];

int calc(int i, int j) {
  int& ans = dp[i][j];
  if (ans != -1) return ans;
  if (i == j) return ans = 0;
  if (i + 1 == j) {
    return ans = matrixes[i].first * matrixes[j].first * matrixes[j].second;
  }

  ans = 2e9;
  for (int k = i; k <= j - 1; ++k) {
    int cost = matrixes[i].first * matrixes[k].second * matrixes[j].second;

    ans = min(ans, calc(i, k) + calc(k + 1, j) + cost);
  }

  return ans;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> N;
  memset(dp, -1, sizeof(dp));

  for (int i = 0; i < N; ++i) {
    int R, C;
    cin >> R >> C;
    matrixes[i] = { R, C };
  }

  cout << calc(0, N - 1) << "\n";

  return 0;
}