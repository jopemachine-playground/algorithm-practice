/*
==============================+===============================================================
@ Title : 나머지 합
@ Desc : cnt[i] = k를 만족시키는 i의 갯수를 k마다 모두 구해주면 되는 문제.
2015 문제와 매우 유사.
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

int nums[1000001];
int sums[1000001];

int solve() {
  _FASTIOS;
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
    nums[i] %= M;
  }

  // 2015 문제와 다르게 음수 키 값이 들어올 일이 없으므로 그냥 배열쓰면 된다.
  vector<ll> cnt(M, 0);
  cnt[0] = 1;

  int sum = 0;
  for (int i = 0; i < N; ++i) {
    sum += nums[i];
    sum %= M;
    ++cnt[sum];
  }

  ll ans = 0;
  for (int i = 0; i < M; ++i) {
    ans += (cnt[i] * (cnt[i] - 1)) / 2LL;
  }

  cout << ans << '\n';

  return 0;
}