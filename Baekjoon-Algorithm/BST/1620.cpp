/*
==============================+===============================================================
@ Title : 나는야 포켓몬 마스터 이다솜
@ Desc :
@ Ref :
==============================+===============================================================
*/

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
#define ll long long
#define pii pair<int, int>

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

int solve() {
  _FASTIOS;

  int N, M;
  cin >> N >> M;
  vector<string> names(N);
  unordered_map<string, int> map;
  int idx = 1;
  for (string& name : names) {
    cin >> name;
    map.insert({name, idx++});
  }
  while (M--) {
    string query;
    cin >> query;
    if (isdigit(query[0])) {
      cout << names[stoi(query) - 1] << '\n';
    }
    else {
      cout << map[query] << '\n';
    }
  }
  return 0;
}
