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

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<pair<long long, long long>> pts(N);

  for (int i = 0; i < N; ++i) {
    cin >> pts[i].first >> pts[i].second;
  }

  pts.push_back({ pts[0].first, pts[0].second });

  long long res = 0;

  for (int i = 0; i < N; ++i) {
    res += pts[i].first * pts[i + 1].second;
    res -= pts[i + 1].first * pts[i].second;
  }

  if (res < 0) res = -res;

  cout << (res / 2) << (res % 2 == 0 ? ".0" : ".5") << "\n";

  return 0;
}