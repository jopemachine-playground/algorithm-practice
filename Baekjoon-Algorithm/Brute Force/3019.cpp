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
#define pii pair<int, int>

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

vector<vector<string>> blockBasesList = {
  {},
  {"0", "0000"},
  {"00"},
  {"001", "10"},
  {"100", "01"},
  {"000", "10", "101", "01"},
  {"000", "20", "011", "00"},
  {"000", "00", "110", "02"}
};

int calc(vector<int>& heights, vector<string>& blockBases) {
  int ans = 0;
  for (string base : blockBases) {
    // i 점에 블록의 가장 왼쪽 점부터 놓기 시작하자.
    for (int i = 0; i + base.length() <= heights.size(); ++i) {
      int valid = true;
      int baseHeight = heights[i] - (base[0] - '0');

      for (int j = 0; j < base.length(); ++j) {
        if (baseHeight != heights[i + j] - (base[j] - '0')) {
          valid = false;
        }
      }

      if (valid) ++ans;
    }
  }
  return ans;
}

int solve() {
  _FASTIOS;
  int C, P;
  cin >> C >> P;
  vector<int> heights(C);
  for (int i = 0; i < C; ++i) {
    cin >> heights[i];
  }

  int ans = 0;
  vector<string> blockBases = blockBasesList[P];
  ans += calc(heights, blockBases);

  cout << ans << '\n';

  return 0;
}