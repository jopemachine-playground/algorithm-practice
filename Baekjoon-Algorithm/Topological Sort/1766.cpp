/*
==============================+===============================================================
@ Title : 문제집
@ Desc : 우선 순위 큐를 이용한 BFS를 통한 위상 정렬
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

vector<int> map[32001];
int indegrees[32001];

int solve() {
  _FASTIOS;
  int N, M;
  cin >> N >> M;
  while (M--) {
    int A, B;
    cin >> A >> B;
    map[A].push_back(B);
    indegrees[B]++;
  }

  priority_queue<int> minHeap;

  for (int i = 1; i <= N; ++i) {
    if (indegrees[i] == 0) {
      minHeap.push(-i);
    }
  }

  while (!minHeap.empty()) {
    int problemNumber = -minHeap.top();
    minHeap.pop();

    cout << problemNumber << ' ';

    vector<int>& linkedList = map[problemNumber];
    for (int& dest : linkedList) {
      indegrees[dest] -= 1;

      if (indegrees[dest] == 0) {
        minHeap.push(-dest);
      }
    }
  }

  cout << "\n";

  return 0;
}