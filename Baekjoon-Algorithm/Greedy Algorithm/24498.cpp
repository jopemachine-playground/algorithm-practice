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
#define endl '\n'

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> heights(N);
  for (int i = 0; i < N; ++i) {
    cin >> heights[i];
  }

  if (N == 1) {
    cout << heights[0] << "\n";
  } else if (N == 2) {
    cout << max(heights[0], heights[1]) << "\n";
  } else {
    // 직접 다 더해보자.
    long long maxHeight = max(heights[0], heights[heights.size() - 1]);

    for (int i = 1; i < N - 1; ++i) {
      long long left = heights[i - 1];
      long long right = heights[i + 1];
      // 인접한 두 탑과 선택한 탑의 높이가 1 이상이어야 한다.
      // if (left < 1 || right < 1 || heights[i] < 1) continue;

      long long res = heights[i] + min(left, right);
      maxHeight = max(maxHeight, res);
    }

    cout << maxHeight << "\n";
  }

  return 0;
}