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
bool dp[5001][5001];
int scoreKind[11];

void go(int i, int j) {
  if (i > N) {
    return;
  }

  bool& ans = dp[i][j];
  if (ans != false) return;
  ans = true;

  for (int k = 0; k < M; ++k) {
    go(i + j + scoreKind[k], j + scoreKind[k]);
  }
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
      cin >> scoreKind[i];
    }

    memset(dp, 0, sizeof(dp));

    go(0, 0);

    int res = -1;
    for (int i = N; i >= 0; --i) {
      if (dp[N][i]) {
        res = i;
        break;
      }
    }
    cout << res << "\n";
  }

  return 0;
}