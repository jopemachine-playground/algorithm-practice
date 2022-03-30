/*
==============================+===============================================================
@ Title : 0과 1
@ Desc : mod 연산자의 성질로 시간 복잡도를 O(N)으로 줄일 수 있는 BFS 문제
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

int solve() {
  _FASTIOS;
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    // 나머지로 BFS를 돌릴 큐
    queue<int> que;
    vector<int> from(N, -1);
    vector<int> how(N, -1);
    vector<int> dist(N, -1);

    // N이 1인 경우에만 0 푸시.
    int start = 1 % N;
    que.push(start);
    dist[start] = 0;
    how[start] = 1;

    while (!que.empty()) {
      int curr = que.front();
      que.pop();
      for (int i = 0; i <= 1; ++i) {
        int r = (curr * 10 + i) % N;
        if (dist[r] != -1) continue;
        dist[r] = dist[curr] + 1;
        from[r] = curr;
        how[r] = i;
        que.push(r);
      }
    }

    if (dist[0] == -1) {
      cout << "BRAK\n"; 
    } else {
      // from, how 배열로 답 역추적
      string res = "";
      for (int i = 0; i != -1; i = from[i]) {
        res += to_string(how[i]);
      }
      reverse(res.begin(), res.end());

      cout << res << '\n';
    }
  }

  return 0;
}