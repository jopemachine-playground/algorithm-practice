/*
==============================+===============================================================
@ Title : 구간 합 구하기 4
@ Desc :
@ Ref :
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

  int N, M;
  cin >> N >> M;
  vector<int> sums(N, 0);

  for (int i = 0; i < N; ++i) {
    int t;
    cin >> t;
    sums[i] = i == 0 ? t : sums[i - 1] + t;
  }

  while (M--) {
    int s, e;
    cin >> s >> e;
    cout << sums[e - 1] - (s <= 1 ? 0 : sums[s - 2]) << "\n";
  }
  return 0;

}
