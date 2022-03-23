/*
==============================+===============================================================
@ Title : 궁금한 민호
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

int minDists[21][21];
int graph[21][21];
const int INF = 2e9;

int solve() {
  _FASTIOS;
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> minDists[i][j];
      graph[i][j] = minDists[i][j];
    }
  }

  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      if (i == k) continue;
      for (int j = 0; j < N; ++j) {
        if (i == j) continue; 
        if (j == k) continue;
        // 애초에 입력으로 주어진 최단 거리 배열이 잘못된 경우
        if (minDists[i][j] > minDists[i][k] + minDists[k][j]) {
          cout << -1 << '\n';
          return 0;
        }

        if (minDists[i][j] == minDists[i][k] + minDists[k][j]) {
          graph[i][j] = INF;
        }
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (graph[i][j] != INF) {
        sum += graph[i][j];
      }
    }
  }

  cout << sum << '\n';

  return 0;
}