/*
==============================+===============================================================
@ Title : 어린 왕자
@ Desc : 두 점을 모두 포함하는 원들을 제거한다면,
두 점 각각에 대해 점을 포함하는 원들의 갯수를 더해주면 되는 간단한
문제가 된다.
(원들이 교차하지도 않고 경계가 맞닿는 경우도 없기 때문)
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

typedef pair<pii, int> Circle;

int getDistSquare(pii p1, pii p2) {
  return (int) pow(p2.second - p1.second, 2) + pow(p2.first - p1.first, 2);
}

bool isIncluded(pii pt, Circle& circle) {
  int radiusSquare = (int) pow(circle.second, 2);
  int distSquare = getDistSquare(pt, circle.first);
  return radiusSquare > distSquare;
}

int solve() {
  _FASTIOS;

  int T;
  cin >> T;
  while (T--) {
    pii startPt, endPt;
    cin >> startPt.first >> startPt.second;
    cin >> endPt.first >> endPt.second;

    int N;
    cin >> N;
    vector<Circle> circles;
    while (N--) {
      int x, y, r;
      cin >> x >> y >> r;
      circles.push_back({{x, y}, r});
    }

    int result = 0;
    for (auto& circle : circles) {
      bool startPtIncluded = isIncluded(startPt, circle);
      bool endPtIncluded = isIncluded(endPt, circle);
      if (startPtIncluded && endPtIncluded) continue;
      else if (startPtIncluded) ++result;
      else if (endPtIncluded) ++result;
    }

    cout << result << endl;
  }
  return 0;
}
