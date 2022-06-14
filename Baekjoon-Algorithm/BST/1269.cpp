/*
==============================+===============================================================
@ Title : 대칭 차집합
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

  set<int> setA;

  int N, M;
  cin >> N >> M;
  int num;

  int intersected = 0;

  for (int i = 0; i < N; ++i) {
    cin >> num;
    setA.insert(num);
  }

  for (int i = 0; i < M; ++i) {
    cin >> num;
    if (setA.find(num) != setA.end()) {
      intersected++;
    }
  }

  cout << N + M - intersected * 2;

  return 0;
}
