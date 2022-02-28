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

bool isP (int x) {
  // 1 자릿수
  if (x <= 9) return true;
  // 2 자릿수
  if (x < 100 && x >= 10) return (x % 10 == x / 10);
  // 3 자릿수
  if (x < 1000 && x >= 100) return (x % 10) == (x / 100);
  // 4 자릿수
  if (x < 9999 && x >= 1000) return (x % 10 == x / 1000) && (((x % 100) / 10) == (x / 100) % 10);
  // 5 자릿수
  if (x < 100000 && x >= 10000) return (x % 10) == (x / 10000) && (((x % 100) / 10) == (x / 1000) % 10);

  return true;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  while (true) {
    cin >> N;
    if (N == 0) break;

    cout << (isP(N) ? "yes" : "no") << "\n";
  }
  return 0;
}