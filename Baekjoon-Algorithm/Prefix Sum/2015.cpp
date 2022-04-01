/*
==============================+===============================================================
@ Title : 수들의 합 4
@ Desc :
@ Ref : 백준 알고리즘 중급
==============================+===============================================================
*/

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
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
#define endl '\n'
#define ll long long
#define pii pair<int, int>

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

int solve() {
  _FASTIOS;
  int N, K;
  cin >> N >> K;
  vector<int> nums(N + 1, 0);
  vector<int> prefixSums(N + 1, 0);

  for (int i = 1; i <= N; ++i) {
    cin >> nums[i];
    prefixSums[i] = prefixSums[i - 1] + nums[i];
  }

  map<int, int> cntMap;

  // 따로 ans 구하는 로직을 분리하지 않고, 
  // cntMap에 넣으면서 ans을 구할 수 있다!
  ll ans = 0;
  cntMap[0] = 1;

  for (int j = 1; j <= N; ++j) {
    ans += cntMap[prefixSums[j] - K];
    ++cntMap[prefixSums[j]];
  }

  cout << ans << '\n';

  return 0;
}