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
int dp[1001][1001];
int lens[1001];

int calc(int idx, int cnt) {
  int& ans = dp[idx][cnt];
  if (ans != -1) return ans;
  if (idx >= N) return ans = 0;
  
  int space = M - cnt + 1;

  ans = calc(idx + 1, lens[idx]) + (space * space);
  if (cnt + lens[idx] - 1 <= M) {
    ans = min(ans, calc(idx + 1, cnt + lens[idx]));
  }

  return ans;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> lens[i];
    // 빈 칸을 아예 포함시켜 버리자.
    ++lens[i];
  }
  memset(dp, -1, sizeof(dp));

  cout << calc(0, 0) << "\n";

  return 0;
}