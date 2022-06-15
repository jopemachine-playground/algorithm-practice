/*
==============================+===============================================================
@ Title : 인간-컴퓨터 상호작용
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
  int N;
  cin >> N;
  int cnts[str.size()][26];
  memset(cnts, 0, sizeof(int) * str.size() * 26);

  cnts[0][str.at(0) - 'a'] = 1;
  for (int i = 1; i < str.size(); ++i) {
    for (int j = 0; j < 26; ++j) {
      if (str.at(i) - 'a' == j) {
        cnts[i][j] = cnts[i - 1][j] + 1;
      }
      else {
        cnts[i][j] = cnts[i - 1][j];
      }
    }
  }

  while (N--) {
    char ch;
    int start, end;
    cin >> ch;
    cin >> start >> end;

    cout << cnts[end][ch - 'a'] - (start == 0 ? 0 : cnts[start - 1][ch - 'a']) << "\n";
  }

  return 0;
}
