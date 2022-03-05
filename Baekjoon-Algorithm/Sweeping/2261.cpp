// 백준 알고리즘 중급
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
// #define pii pair<int, int>

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

struct pii {
  int first;
  int second;
  bool operator < (const pii& v) const {
    if (second == v.second) {
      return first < v.first;
    }
    return second < v.second;
  }
};

int dist (pii u, pii v) {
  return (u.second - v.second) * (u.second - v.second) + (u.first - v.first) * (u.first - v.first);
}

int solve() {
  _FASTIOS;
  int N;
  cin >> N;
  vector<pii> pts(N);
  for (int i = 0; i < N; ++i) {
    cin >> pts[i].first >> pts[i].second;
  }

  sort(pts.begin(), pts.end(), [](pii& u, pii& v) {
    return u.first < v.first;
  });
  
  int d = dist(pts[0], pts[1]);
  
  set<pii> candidates;
  candidates.insert(pts[0]);
  candidates.insert(pts[1]);

  int start = 0;
  // 스위핑도 결국 부분 문제를 반복적으로 풀어서 값을 찾아내는 방식이다.
  // 점 하나 추가하고 d 갱신하고, 하나 추가하고 다시 갱신하고..
  for (int i = 2; i < N; ++i) {
    while (start < i) {
      int dx = pts[i].first - pts[start].first;
      if (dx * dx > d) {
        candidates.erase(pts[start]);
        ++start;
      } else {
        break;
      }
    }

    int dy = (int) sqrt((double) d);
    auto lower_point = pii({-100000, pts[i].second - dy});
    auto upper_point = pii({+100000, pts[i].second + dy});
    auto lower = candidates.lower_bound(lower_point);
    auto upper = candidates.upper_bound(upper_point);

    for (auto it = lower; it != upper; ++it) {
      d = min(d, dist(*it, pts[i]));
    }

    candidates.insert(pts[i]);
  }

  cout << d << "\n";

  return 0;
}