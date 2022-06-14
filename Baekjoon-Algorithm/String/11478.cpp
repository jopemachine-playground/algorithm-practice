/*
==============================+===============================================================
@ Title : 서로 다른 부분 문자열의 개수
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

  string str;
  cin >> str;

  set<string> substrSet;

  for (int i = 0; i < str.size(); ++i) {
    for (int j = i; j < str.size(); ++j) {
      substrSet.insert(str.substr(i, j - i + 1));
    }
  }
  cout << substrSet.size() << "\n";
  return 0;
}
