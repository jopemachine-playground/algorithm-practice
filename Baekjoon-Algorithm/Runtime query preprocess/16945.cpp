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

vector<vector<int>> magicArrays = {
  {2,7,6,9,5,1,4,3,8},
  {2,9,4,7,5,3,6,1,8},
  {4,3,8,9,5,1,2,7,6},
  {4,9,2,3,5,7,8,1,6},
  {6,1,8,7,5,3,2,9,4},
  {6,7,2,1,5,9,8,3,4},
  {8,1,6,3,5,7,4,9,2},
  {8,3,4,1,5,9,6,7,2}
};

int diff(vector<int>& A, vector<int>& D) {
  int ans = 0;
  for (int i = 0; i < A.size(); ++i) {
    ans += abs(A[i] - D[i]);
  }
  return ans;
}

int solve() {
  _FASTIOS;
  // 이렇게 미리 매직 스퀘어에 해당하는 값을 구하고 문제를 푸는 경우에도
  // 일차원 배열을 쓰는 편이 훨씬 깔끔하게 풀 수 있어 유리함.
  vector<int> A(9);
  for (int i = 0; i < 9; ++i) {
    cin >> A[i];
  }

  int ans = 2e9;
  for (int i = 0; i < magicArrays.size(); ++i) {
    ans = min(ans, diff(A, magicArrays[i]));
  }

  cout << ans << "\n";

  return 0;
}