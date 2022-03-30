/*
==============================+===============================================================
@ Title : 퍼즐
@ Desc : 8 퍼즐 문제. swap을 이용해 간단하게 퍼즐의 상태를 변경하는 방법을 잘 봐둬야겠다..
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

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

int solve() {
  _FASTIOS;
  int start = 0;

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      int k;
      cin >> k;
      // 0을 9로 표현하면 퍼즐의 상태를 int 하나로 표현할 수 있다.
      if (k == 0) k = 9;
      start = start * 10 + k;
    }
  }

  queue<int> que;
  que.push(start);
  map<int, int> dist;
  dist[start] = 0;
  while (!que.empty()) {
    int curr = que.front(); que.pop();
    string str = to_string(curr);
    int zeroIdx = str.find('9');
    int r = zeroIdx / 3;
    int c = zeroIdx % 3;

    for (int k = 0; k < 4; ++k) {
      int nr = r + dr[k];
      int nc = c + dc[k];
      if (nr >= 0 && nc >= 0 && nr < 3 && nc < 3) {
        string next = str;
        swap(next[r * 3 + c], next[nr * 3 + nc]);
        int nextNum = stoi(next);
        if (dist.count(nextNum) == 0) {
          dist[nextNum] = dist[curr] + 1;
          que.push(nextNum);
        }
      }
    }
  }

  if (dist.count(123456789) == 0) {
    cout << -1 << '\n';
  } else {
    cout << dist[123456789] << '\n';
  }

  return 0;
}