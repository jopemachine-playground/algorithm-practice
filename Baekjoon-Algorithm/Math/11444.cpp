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

using matrix = vector<vector<long long>>;

const long long mod = 1000000007LL;

// 행렬의 곱셈
matrix operator * (const matrix& u, const matrix& v) {
  matrix res(u[0].size(), vector<long long>(v.size()));
  // u:: N * M
  // v:: M * K
  // 행렬의 곱셈을 하기 위해선, u의 col 갯수와 v의 row 갯수는 같아야 한다.
  assert(u[0].size() == v.size());

  for (int i = 0; i < u.size(); ++i) {
    for (int j = 0; j < v[0].size(); ++j) {
      for (int k = 0; k < u[0].size(); ++k) {
        res[i][j] += u[i][k] * v[k][j];
      }
      res[i][j] %= mod;
    }
  }

  return res;
}

matrix pow(const matrix& A, long long N) {
  if (N == 1) return A;

  if (N % 2 == 0) {
    matrix tmp = pow(A, N / 2);
    return tmp * tmp;
  }
  else {
    return pow(A, N - 1) * A;
  }
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  long long N;
  cin >> N;
  if (N == 1) {
    cout << 1 << "\n";
    return 0;
  }

  matrix A = {{1, 1}, {1, 0}};
  matrix origin = {{1}, {0}};
  cout << (pow(A, N - 1) * origin)[0][0] << "\n";

  return 0;
}