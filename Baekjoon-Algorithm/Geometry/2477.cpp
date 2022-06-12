/*
==============================+===============================================================
@ Title : 참외밭
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

  int multiplier;
  cin >> multiplier;

  vector<pair<int, int>> pts;

  int dr = 0, dc = 0;

  int N = 6;
  while (N--) {
    int type, diff;
    cin >> type >> diff;

    if (type == 1) {
        dr += diff;
    }
    else if (type == 2) {
        dr -= diff;
    }
    else if (type == 3) {
        dc -= diff;
    }
    else if (type == 4) {
        dc += diff;
    }

    pts.push_back({ dr, dc });
  }

  pts.push_back(pts[0]);

  int result = 0;

  for (int i = 0; i < 6; ++i) {
    result += pts[i].first * pts[i + 1].second;
    result -= pts[i].second * pts[i + 1].first;
  }

  if (result < 0) result = -result;

  cout << (multiplier * result) / 2 << "\n";

  return 0;
}
