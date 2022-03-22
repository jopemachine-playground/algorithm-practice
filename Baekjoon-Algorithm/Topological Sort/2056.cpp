/*
==============================+===============================================================
@ Title : 작업
@ Desc : 위상 정렬 응용 문제.
단순히 위상 정렬한 결과를 출력하는 게 아니라, 순회하면서 가장 오래 걸리는 작업 path의 시간을 재야한다.
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

vector<int> graph[10001];
int indegrees[10001];
int costs[10001];
int dist[10001];

int solve() {
  _FASTIOS;
  int N;
  cin >> N;

  for (int i = 1; i <= N; ++i) {
    int cost, followingCnt;
    cin >> cost >> followingCnt;
    costs[i] = cost;

    while (followingCnt--) {
      int following;
      cin >> following;
      graph[following].push_back(i);
      indegrees[i]++;
    }
  }

  queue<int> que;
  for (int i = 1; i <= N; ++i) {
    if (indegrees[i] == 0) {
      que.push(i);
      dist[i] = costs[i];
    }
  }

  while (!que.empty()) {
    int curr = que.front();
    que.pop();

    vector<int>& linkedList = graph[curr];

    for (int i = 0; i < linkedList.size(); ++i) {
      int dest = linkedList[i];
      --indegrees[dest];

      dist[dest] = max(dist[dest], dist[curr] + costs[dest]);

      if (indegrees[dest] == 0) {
        que.push(dest);
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    ans = max(ans, dist[i]);
  }
  cout << ans << '\n';

  return 0;
}