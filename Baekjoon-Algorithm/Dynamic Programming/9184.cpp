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

int dp[51][51][51];

int w (int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0) return 1;
  int& ans = dp[a][b][c];
  if (ans != -1) return ans;
  if (a > 20 || b > 20 || c > 20) return ans = w (20, 20, 20);
  if (a < b && b < c) return ans = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
  else return ans = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
  return ans;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  memset(dp, -1, sizeof dp);
  while (true) {
    int A, B, C;
    cin >> A >> B >> C;
    if (A == -1 && B == -1 && C == -1) break;
    cout << "w(" << A << ", " << B << ", " << C << ") = " << w(A, B, C) << "\n";
  }
  return 0;
}