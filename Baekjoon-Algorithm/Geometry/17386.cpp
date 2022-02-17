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

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  pair<long long, long long> P1, P2, P3, P4;
  cin >> P1.first >> P1.second;
  cin >> P2.first >> P2.second;
  cin >> P3.first >> P3.second;
  cin >> P4.first >> P4.second;

  if (
    (ccw(P1, P2, P3) * ccw(P1, P2, P4) == -1) &&
    (ccw(P3, P4, P2) * ccw(P3, P4, P1) == -1)
  ) {
    cout << 1 << "\n";
  } else {
    cout << 0 << "\n";
  }

  return 0;
}