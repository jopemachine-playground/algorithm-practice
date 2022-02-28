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

#define ll long long

// 유클리드 알고리즘
int gcd (int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}

// 최소공배수 = 두 자연수의 곱 / 최대공약수
int lcm(int x, int y) {
  return (x * y / gcd(x, y));
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  cout << gcd(N, M) << "\n" << lcm(N, M) << "\n";

  return 0;
}