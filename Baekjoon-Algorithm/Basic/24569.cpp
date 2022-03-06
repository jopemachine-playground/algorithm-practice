/*
==============================+===============================================================
@ Title : Fergusonball Ratings
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
  int N;
  cin >> N;
  int ans = 0;

  for (int i = 0; i < N; ++i) {
    int scores, fouls;
    cin >> scores >> fouls;
    if (scores * 5 - fouls * 3 > 40) ++ans;
  }

  cout << ans;
  if (ans == N) cout << '+';
  cout << '\n';

  return 0;
}