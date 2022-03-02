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

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

#define ll long long

int solve() {
  _FASTIOS;
  int N;
  cin >> N;

  int cnt2 = 0;
  int cnt5 = 0;

  if (N == 0) {
    cout << 0 << "\n";
    return 0;
  }

  do {
    int k1 = N;
    int k2 = N;

    while (k1 % 2 == 0) {
      ++cnt2;
      k1 /= 2;
    }

    while (k2 % 5 == 0) {
      ++cnt5;
      k2 /= 5;
    }
  } while (--N);

  cout << min(cnt2, cnt5) << "\n";

  return 0;
}