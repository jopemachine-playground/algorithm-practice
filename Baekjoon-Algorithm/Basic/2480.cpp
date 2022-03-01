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

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int A, B, C;
  cin >> A >> B >> C;
  int res = -1;

  if (A == B && B == C && A == C) {
    res = A * 1000 + 10000;
  }
  else if (A == B || B == C || C == A) {
    int same = -1;
    if (A == B) {
      same = A;
    }
    if (B == C) {
      same = B;
    }
    if (C == A) {
      same = C;
    }
    res = same * 100 + 1000;
  } 
  else {
    res = 100 * max(A, max(B, C));
  }

  cout << res << "\n";

  return 0;
}