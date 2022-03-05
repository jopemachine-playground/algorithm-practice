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

int N, M;

int solve() {
  _FASTIOS;
  do {
    cin >> N >> M;
    if (N == 0 && M == 0) break;

    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        cin >> map[i][j];
      }
    }

    vector<vector<int>> heightsMap(N, vector<int>(M));
    for (int j = 0; j < M; ++j) {
      heightsMap[0][j] = map[0][j];
    }

    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (map[i][j] == 1) {
          heightsMap[i][j] = map[i][j] + heightsMap[i - 1][j];
        } else {
          heightsMap[i][j] = 0;
        }
      }
    }

    int maxArea = 0;

    // i행을 base행으로 보고 그 위에서 가장 큰 직사각형을 찾는다.
    for (int h = 0; h < N; ++h) {
      vector<int> heights = heightsMap[h];
      stack<int> stk;

      for (int i = 0; i < M; ++i) {
        while (!stk.empty() && heights[stk.top()] > heights[i]) {
          int h = heights[stk.top()];
          stk.pop();
          int w = stk.empty() ? i : i - stk.top() - 1;
          maxArea = max(maxArea, h * w);
        }

        stk.push(i);
      }

      while (!stk.empty()) {
        int h = heights[stk.top()];
        stk.pop();
        int w = stk.empty() ? M : M - stk.top() - 1;
        maxArea = max(maxArea, h * w);
      }
    }

    cout << maxArea << "\n";

  } while (N != 0 && M != 0);
  return 0;
}