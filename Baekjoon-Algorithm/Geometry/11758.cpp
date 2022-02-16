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

// 외적을 이용해 CCW 알고리즘으로 방향 판별.
int ccw(pair<int, int> P1, pair<int, int> P2, pair<int, int> P3) {
  int front = (P1.first * P2.second) + (P2.first * P3.second) + (P3.first * P1.second);
  int back  = (P2.first * P1.second) + (P3.first * P2.second) + (P1.first * P3.second);
  int out = front - back;
  if (out == 0) return 0;

  else if (out > 0) {
    return 1;
  } else {
    return -1;
  }
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  pair<int, int> P1, P2, P3;

  cin >> P1.first >> P1.second;
  cin >> P2.first >> P2.second;
  cin >> P3.first >> P3.second;

  cout << ccw(P1, P2, P3) << "\n";
  return 0;
}