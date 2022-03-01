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

#define ll long long

int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}

int lcm(int x, int y) {
  return (x * y) / gcd(x, y);
}

// int main() {
int solve() {
  _FASTIOS;
  int N;
  cin >> N;
  while (N--) {
    int A, B;
    cin >> A >> B;
    cout << lcm(A, B) << "\n";
  }
  return 0;
}