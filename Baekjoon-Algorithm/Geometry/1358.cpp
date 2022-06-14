/*
==============================+===============================================================
@ Title : 하키
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

typedef struct {
  int x;
  int y;
  int r;
} Circle;

int getDistSquare(int x1, int y1, int x2, int y2) {
  return (int) pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

bool isInsideCircle(Circle& circle, int x, int y) {
  return (int) pow(circle.r, 2) >= getDistSquare(circle.x, circle.y, x, y);
}

int solve() {
  _FASTIOS;

  int W, H, X, Y, P;
  cin >> W >> H >> X >> Y >> P;
  int R = H / 2;
  int result = 0;

  Circle circle1 = Circle {X, Y + R, R};
  Circle circle2 = Circle {X + W, Y + R, R};

  for (int i = 0; i < P; ++i) {
    int x, y;
    cin >> x >> y;
    // inside of rectangle area
    if (x >= X && x <= X + W && y >= Y && y <= Y + H) {
      ++result;
    }
    // inside of circles
    else if (isInsideCircle(circle1, x, y) || isInsideCircle(circle2, x, y)) {
      ++result;
    }
  }
  cout << result;
  return 0;
}
