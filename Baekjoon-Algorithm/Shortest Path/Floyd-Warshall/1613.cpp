/*
==============================+===============================================================
@ Title : 역사
@ Desc : 위상정렬 문제처럼 보이지만 그래프의 연결성을 묻는 문제이다.
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

int d[401][401];

int solve() {
  _FASTIOS;
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < K; ++i) {
    int A, B;
    cin >> A >> B;

    d[A][B] = 1;
  }

  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (d[i][k] == 1 && d[k][j] == 1) {
          d[i][j] = 1;
        }
      }
    }
  }

  int S;
  cin >> S;

  while (S--) {
    int A, B;
    cin >> A >> B;

    if (d[A][B] == 1 && d[B][A] == 0) {
      cout << -1 << '\n';
    }
    else if (d[A][B] == 0 && d[B][A] == 1) {
      cout << 1 << '\n';
    }
    else {
      cout << 0 << '\n';
    }
  }

  return 0;
}