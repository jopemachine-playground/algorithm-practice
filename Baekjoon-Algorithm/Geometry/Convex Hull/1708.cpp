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

using Point = pair<long long, long long>;

Point leftBottom;

int ccw(pair<long long,long long> P1, pair<long long,long long> P2, pair<long long,long long> P3) {
  long long front = P1.first * P2.second + P2.first * P3.second + P3.first * P1.second;
  long long back = P1.second * P2.first + P2.second * P3.first + P3.second * P1.first;
  long long out = front - back;

  if (out == 0) return 0;
  else if (out > 0) {
    return 1;
  }
  else {
    return -1;
  }
}

// 비교함수에 사용되는 거리를 구하는 함수. 굳이 루트를 씌울 필요 없다.
long long dist(const Point& u, const Point& v) {
  long long dx = u.first - v.first;
  long long dy = u.second - v.second;
  return dx * dx + dy * dy;
}

// 각도가 작고 거리가 짧은 점들이 앞게 오게 정렬하는 함수.
// => 각도에 대해 정렬하는 대신 leftBottom을 시작점으로, 각 점들을 끝점으로 하는 선분들이 반시계방향으로 돌도록 점들을 정렬하면 된다.
// (실수인 각도를 구하는 대신 정수를 이용한 비교함수를 작성하는게 수치적으로 안정적이고 빠르다.)
bool compare(const Point& u, const Point& v) {
  int ccwVal = ccw(leftBottom, u, v);
  // 세 점이 일직선 위에 있는 경우 거리를 비교한다.

  if (ccwVal == 0) {
    return dist(leftBottom, u) <= dist(leftBottom, v);
  }
  // 벡터 외적값(ccw)이 양수 값일 때 반시계 방향이란 것을 나타낸다. 
  // 그래서 counter 가 붙어 있는 것
  // 즉, 모든 점들이 반시계방향으로 돌도록 정렬해준다.
  else {
    return ccwVal == 1;
  }
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

  leftBottom = pts[0];
  // 가장 왼쪽 아래에 있는 점을 찾는다.
  for (int i = 1; i < N; ++i) {
    if (
      pts[i].second < leftBottom.second ||
      (pts[i].second == leftBottom.second && pts[i].first < leftBottom.first)
    ) {
      leftBottom = pts[i];
    }
  }

  sort(pts.begin(), pts.end(), compare);

  // 가장 왼쪽 아랫쪽 점 기준으로 항상 반시계방향으로 돌도록 정렬된 점들을 순회하면서 
  // 스택의 두 점과 현재 보고 있는 한 점이 항상 시계 방향으로 돌도록
  // 스택에 점들을 push 해 나간다.
  vector<Point> ptStk;

  for (int i = 0; i < N; ++i) {
    // ccw가 0보다 작거나 같다면 시계방향이거나 세 점이 한 직선위에 있는 경우이므로 스택에서 점을 하나 빼고 다시 트라이 해야 한다.
    while (ptStk.size() >= 2 && ccw(ptStk[ptStk.size() - 2], ptStk[ptStk.size() - 1], pts[i]) <= 0) {
      ptStk.pop_back();
    }
    ptStk.push_back(pts[i]);
  }

  cout << ptStk.size() << '\n';

  return 0;
}