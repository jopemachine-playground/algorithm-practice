/*
==============================+===============================================================
@ Title : 일방통행
@ Desc :
@ Ref : 백준 알고리즘 중급
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

int graph[51][51];
int d[51][51];

int solve() {
  _FASTIOS;
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    assert(str.length() == N);

    for (int j = 0; j < N; ++j) {
      if (str[j] == 'Y') {
        graph[i][j] = 1;
      } else {
        graph[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (graph[i][j] == 1 && graph[j][i] == 0) {
        d[i][j] = 1;
      }
    }
  }

  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (d[i][k] == 1 && d[k][j] == 1) {
          d[i][j] = 1;
        }
      }
    }
  }

  auto ans = "YES";

  for (int i = 0; i < N; ++i) {
    if (d[i][i] == 1) {
      ans = "NO";
      break;
    }
  }

  cout << ans << '\n';

  return 0;
}