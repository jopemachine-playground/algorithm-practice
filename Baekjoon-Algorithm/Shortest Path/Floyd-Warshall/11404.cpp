/*
==============================+===============================================================
@ Title : 플로이드
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

int d[101][101];

int INF = 1e9;

int solve() {
  _FASTIOS;
  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (i == j) {
        d[i][j] = 0;
      }
      else {
        d[i][j] = INF;
      }
    }
  }

  while (M--) {
    int A, B, C;
    cin >> A >> B >> C;
    // 두 정거장을 잇는 노선은 2개 이상일 수 있다
    // 그런 경우엔 더 코스트가 적은 노선만 고려하면 된다.
    d[A][B] = min(d[A][B], C);
  }

  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (d[i][j] == INF) cout << 0 << ' ';
      else cout << d[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}