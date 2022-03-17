/*
==============================+===============================================================
@ Title : 줄 세우기
@ Desc : DFS를 통한 위상 정렬.
간선의 방향을 모두 반대로 바꾸고, DFS를 돌리면서 출력하면 위상 정렬의 결과가 된다.
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
#include <tuple>
#include <algorithm>
#include <array>
#include <memory.h>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define debug          \
  if constexpr (LOCAL) \
  cout
#define _FASTIOS cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(0)
#define endl '\n'
#define ll long long
#define pii pair<int, int>

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

vector<int> map[32001];
bool check[32001];

void dfs (int x) {
  check[x] = true;

  for (int dest : map[x]) {
    if (!check[dest]) dfs(dest);
  }

  cout << x << ' ';
}

int solve() {
  _FASTIOS;
  int N, M;
  cin >> N >> M;

  while (M--) {
    int A, B;
    cin >> A >> B;
    map[B].push_back(A);
  }

  for (int i = 1; i <= N; ++i) {
    if (!check[i]) dfs(i);
  }

  cout << '\n';

  return 0;
}