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

// Eluer pi function
ll phi(ll N) {
  double ans = N;

  for (ll i = 2; i * i <= N; ++i) {
    if (N % i == 0) {
      while (N % i == 0) {
        N /= i;
      }

      ans *= (1.0 - (1.0) / i);
    }
  }

  if (N > 1) {
    ans *= (1.0 - (1.0) / N);
  }

  return (ll) ans;
}

// int main() {
int solve() {
  _FASTIOS;
  ll N;
  cin >> N;
  cout << phi(N) << "\n";
  return 0;
}