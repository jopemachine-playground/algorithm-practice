/*
==============================+===============================================================
@ Title : 줄 세우기
@ Desc : BFS를 통한 위상 정렬. 각 점으로 들어오는 점들의 갯수 (indegree)들을 기록해놓고,
indegree가 0인 점들을 모두 큐에 넣는 것으로 시작한다.
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

  queue<int> que;
  for (int i = 1; i <= N; ++i) {
    if (indegrees[i] == 0) {
      que.push(i);
    }
  }

  int pos;
  while (!que.empty()) {
    tie(pos) = que.front();
    que.pop();
    vector<int> &linkedList = map[pos];

    // BFS니까 방문할 때 마다 바로 출력해주면 된다.
    cout << pos << ' ';

    for (int idx = 0; idx < linkedList.size(); ++idx) {
      int dest = linkedList[idx];
      indegrees[dest] -= 1;
      // 목적지 방문 체크의 역할도 indegree로 같이 할 수 있다.
      if (indegrees[dest] == 0) {
        que.push(dest);
      }
    }
  }

  cout << "\n";

  return 0;
}