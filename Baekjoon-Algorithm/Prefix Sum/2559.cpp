/*
==============================+===============================================================
@ Title : 수열
@ Desc :
@ Ref :
==============================+===============================================================
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <memory.h>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define debug                                                                  \
  if constexpr (LOCAL)                                                         \
  cout
#define _FASTIOS cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(0)
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
  vector<int> sums(N);
  for (int i = 0; i < N; ++i) {
    cin >> sums[i];
    sums[i] += i == 0 ? 0 : sums[i - 1];
  }

  int answer = sums[K - 1];
  for (int i = 0; i < N; ++i) {
    if (i >= K) {
      // cout << sums[i] - sums[i - K] <<" ";
      answer = max(answer, (sums[i] - sums[i - K]));
    }
  }

  cout << answer;

  return 0;
}
