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

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

#define ll long long

void left(deque<int>& que) {
  int l = que.front();
  que.push_back(l);
  que.pop_front();
}

void right(deque<int>& que) {
  int r = que.back();
  que.push_front(r);
  que.pop_back();
}

int first(deque<int>& que) {
  int ret = que.front();
  que.pop_front();
  return ret;
}

int solve() {
  _FASTIOS;
  int N, M;
  cin >> N >> M;
  deque<int> que;
  for (int i = 0; i < N; ++i) {
    que.push_back(i);
  }

  int ans = 0;

  for (int i = 0; i < M; ++i) {
    int idx;
    cin >> idx;
    idx -= 1;

    // deque를 회전시킬 때 최소 수행해야 하는 2, 3번 연산의 횟수
    int leftCost = -1;

    for (int i = 0; i < que.size(); ++i) {
      if (que[i] == idx) {
        leftCost = i;
      }
    }

    int rightCost = que.size() - leftCost;

    assert(leftCost != -1);

    int minCnt = min(leftCost, rightCost);
    bool useLeft = leftCost < rightCost ? true : false;

    // cout << "----\n";
    // cout << "leftCost: " << leftCost << "\n";
    // cout << "rightCost: " << rightCost << "\n";

    for (int i = 0; i < minCnt; ++i) {
      if (useLeft) {
        left(que);
      } else {
        right(que);
      }
    }

    first(que);
    ans += minCnt;
  }

  cout << ans << "\n";

  return 0;
}