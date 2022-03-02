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

int solve() {
  _FASTIOS;
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    map<string, int> map;

    for (int i = 0; i < N; ++i) {
      string name, kind;
      cin >> name >> kind;
      map[kind]++;
    }

    int ans = 1;
    for (auto& p : map) {
      ans *= (p.second + 1);
    }
    cout << ans - 1 << "\n";
  }

  return 0;
}