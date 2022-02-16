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

vector<vector<long long>> operator % (const vector<vector<long long>>& A, long long B) {
  vector<vector<long long>> res(A);
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < A[i].size(); ++j) {
      res[i][j] %= B;
    }
  }
  return res;
}

vector<vector<long long>> matrixMulp(vector<vector<long long>>& A, vector<vector<long long>>& B) {
  // A: N1 * M1
  // B: N2 * M2 
  // Res: N1 * M2
  vector<vector<long long>> res(A.size(), vector<long long>(B[0].size(), 0));

  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < B.size(); ++j) {
      for (int k = 0; k < A[0].size(); ++k) {
        res[i][j] += A[i][k] * B[k][j];
      }
      res[i][j] %= 1000;
    }
  }

  return res;
}

vector<vector<long long>> matrixPow(vector<vector<long long>>& A, long long B) {
  if (B == 1) {
    return A % 1000LL;
  }
  if (B % 2 == 0) {
    auto temp = matrixPow(A, B / 2);
    return matrixMulp(temp, temp);
  }
  if (B % 2 == 1) {
    auto temp = matrixPow(A, B - 1);
    return matrixMulp(A, temp);
  }

  assert(false);
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N;
  long long B;

  cin >> N >> B;

  vector<vector<long long>> A(N, vector<long long>(N));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> A[i][j];
    }
  }

  auto ans = matrixPow(A, B);

  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}