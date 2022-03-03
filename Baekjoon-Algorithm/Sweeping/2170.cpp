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
  vector<pii> intervals(N);
  for (int i = 0; i < N; ++i) {
    cin >> intervals[i].first >> intervals[i].second;
  }

  // first 값으로 정렬해 놓은 후 스위핑 하면서 경우의 수를 나눠주자.
  sort(intervals.begin(), intervals.end());

  int left = intervals[0].first, right = intervals[0].second;
  ll lenTotal = 0;

  for (int i = 1; i < N; ++i) {
    if (intervals[i].first >= right) {
      lenTotal += right - left;
      left = intervals[i].first;
      right = intervals[i].second;
    } else {
      right = max(right, intervals[i].second);
    }
  }

  lenTotal += right - left;

  cout << lenTotal << "\n";

  return 0;
}
