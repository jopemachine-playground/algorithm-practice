/*
==============================+===============================================================
@ Title : 수열의 합
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

  int N, L;
  cin >> N >> L;

  int offset = -1;
  int len = -1;

  for (int i = L; i <= 100; ++i) {
    // sum from 1 to L
    int initialSum = (i * (i - 1)) / 2;
    if (N < initialSum) break;

    if ((N - initialSum) % i == 0) {
      offset = (N - initialSum) / i;
      len = i;
      break;
    }
  }

  if (offset == -1) {
    cout << -1;
  } else {
    for (int i = 0; i < len; ++i) {
      cout << i + offset << " ";
    }
  }

  return 0;
}
