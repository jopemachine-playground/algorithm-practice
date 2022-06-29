/*
==============================+===============================================================
@ Title : 분산처리
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
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;

    if (a % 10 == 0) {
      cout << 10 << '\n';
      continue;
    }

    int k = a % 10;
    int prod = 1;

    for (int i = 0; i < b; ++i) {
      prod *= k;
      prod %= 10;
    }

    cout << prod << '\n';
  }
  return 0;
}