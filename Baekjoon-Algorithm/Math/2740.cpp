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

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

vector<vector<int>> matrixMulp(vector<vector<int>>& A, vector<vector<int>>& B) {
  // A: N1 * M1
  // B: N2 * M2 
  // Res: N1 * M2
  vector<vector<int>> res(A.size(), vector<int>(B[0].size(), 0));

  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < B[0].size(); ++j) {
      for (int k = 0; k < A[0].size(); ++k) {
        res[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  return res;
}

// int main() {
int solve() {
  _FASTIOS;
  int N1, M1, N2, M2;
  cin >> N1 >> M1;
  vector<vector<int>> A(N1, vector<int>(M1));

  for (int i = 0; i < N1; ++i) {
    for (int j = 0; j < M1; ++j) {
      cin >> A[i][j];
    }
  }

  cin >> N2 >> M2;
  vector<vector<int>> B(N2, vector<int>(M2));

  for (int i = 0; i < N2; ++i) {
    for (int j = 0; j < M2; ++j) {
      cin >> B[i][j];
    }
  }

  auto ans = matrixMulp(A, B);

  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < ans[0].size(); ++j) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}