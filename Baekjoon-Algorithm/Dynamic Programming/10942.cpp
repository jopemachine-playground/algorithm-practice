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

// S, E들에 대해 각각 N까지 들어가므로 O(N^2). 
// 전체 시간 복잡도 O(N^2 + M).
int query(vector<int>& range, vector<vector<int>>& dp, int S, int E) {
  // Base case 들.
  if (S > E) return false;
  // Base case의 길이가 1인 경우
  if (S == E) return true;
  // Base case의 길이가 2인 경우
  if (S + 1 == E) {
    return (range[S] == range[E] ? 1 : 0);
  }

  // -1이 아닐 때로 체크해도 되고, 0 이상인 경우로 체크해도 됨.
  if (dp[S][E] >= 0) return dp[S][E];

  if (range[S] != range[E]) {
    return dp[S][E] = 0;
  }
  else {
    return dp[S][E] = query(range, dp, S + 1, E - 1);
  }
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> range(N);
  for (auto& i : range) {
    cin >> i;
  }

  int M;
  cin >> M;
  // -1: 초기화 안 됨. 0: 펠린드롬 불가. 1: 펠린드롬 가능
  vector<vector<int>> dp(N, vector<int>(N, -1));

  for (int i = 0; i < M; ++i) {
    int S, E;
    cin >> S >> E;
    cout << query(range, dp, S - 1, E - 1) << '\n';
  }

  return 0;
}