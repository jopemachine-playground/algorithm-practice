// 백준 알고리즘 중급
#include <iostream>
#include <vector>
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

using Point = pair<long long, long long>;
using Line = pair<Point, Point>;

int ccw(Point p1, Point p2, Point p3) {
  long long temp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
  temp -= p1.second * p2.first + p2.second * p3.first + p3.second * p1.first;
  if (temp > 0) return 1;
  else if (temp < 0) return -1;
  return 0;
}

// l1과 l2가 교차하면 1, 교차 안 하면 0 반환
int cross(Line l1, Line l2) {
  int l1l2 = ccw(l1.first, l1.second, l2.first) * ccw(l1.first, l1.second, l2.second);
  int l2l1 = ccw(l2.first, l2.second, l1.first) * ccw(l2.first, l2.second, l1.second);
  return l1l2 < 0 && l2l1 < 0;
}

// people의 위치가 다각형 내부에 있는지 판별하기 위해 우선 교점의 갯수를 센다.
// 교점의 갯수가 홀수인 경우 내부에 있으므로 보호받는다.
// 교점의 갯수가 짝수인 경우 외부에 있으므로 보호 받을 수 없다.
int isInside(Point& people, vector<Point>& pts) {
  // 변에 들어가 있는 경우도 보호 가능하므로 이 부분을 예외 처리해줘야 한다.
  for (int i = 0; i + 1 < pts.size(); ++i) {
    int ccw1 = ccw(pts[i], pts[i + 1], people);
    // 세 점이 한 직선위에 있다.
    if (ccw1 == 0) {
      auto minx = min(pts[i].first, pts[i+1].first);
      auto maxx = max(pts[i].first, pts[i+1].first);
      auto miny = min(pts[i].second, pts[i+1].second);
      auto maxy = max(pts[i].second, pts[i+1].second);

      // people 점이 다각형의 두 점의 중간에 있다.
      if (
        minx <= people.first &&
        miny <= people.second &&
        people.first <= maxx &&
        people.second <= maxy
      ) {
        return 1;
      }
    }
  }

  // 가상의 점을 만들고 가상의 점과 사람 (내부에 있는지 판단하기 위한 점)을 잇는 선분을 그려,
  // 해당 선분과 다각형의 선분들과의 교점의 갯수를 세 줄 것임.
  // 해당 교점의 갯수가 홀수이면 이 점은 내부에 있고 짝수이면 외부에 있다.
  // 이 때 가상의 선분의 기울기가 절대 변과 일치하는 기울기를 가져서는 안 되기 때문에,
  // 모든 좌표를 이루는 수가 10억 이하인 것을 이용해 20억 정도의 값으로 만들어준다.
  Point vPt = {1, 2000000000};
  Line vL = {vPt, people};

  // 교점의 갯수를 세 주자.
  int cnt = 0;
  for (int i = 0; i + 1 < pts.size(); ++i) {
    cnt += cross(vL, Line({ pts[i], pts[i + 1] }));
  }

  return cnt % 2;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<Point> pts(N);
  for (int i = 0; i < N; ++i) {
    cin >> pts[i].first >> pts[i].second;
  }

  // 다각형의 모든 선분들과 그어봐야 하기 때문에, 다각형의 맨 처음 점이 마지막에도 나오게 넣어줘야 한다.
  pts.push_back(pts[0]);

  for (int i = 0; i < 3; ++i) {
    Point people;
    cin >> people.first >> people.second;
    cout << isInside(people, pts) << "\n";
  }
  
  return 0;
}