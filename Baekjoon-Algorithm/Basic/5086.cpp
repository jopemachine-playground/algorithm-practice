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

// int main() {
int solve() {
  _FASTIOS;
  while (true) {
    int N, M;
    cin >> N >> M;
    if (N == 0 && M == 0) break;
    if (M % N == 0) {
      cout << "factor\n";
    } else if (N % M == 0) {
      cout << "multiple\n";
    } else {
      cout << "neither\n";
    }
  }
  return 0;
}