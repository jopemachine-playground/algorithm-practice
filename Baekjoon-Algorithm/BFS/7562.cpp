/*
==============================+===============================================================
@ Title : 나이트의 이동
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

int dr[] = {2,1,-1,-2,-2,-1,1,2};
int dc[] = {1,2,2,1,-1,-2,-2,-1};

int dist[301][301];

int solve() {
  _FASTIOS;

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    memset(dist, -1, sizeof dist);
    pii curr;
    cin >> curr.first >> curr.second;
    pii dest;
    cin >> dest.first >> dest.second;

    queue<pii> que;
    dist[curr.first][curr.second] = 0;
    que.push(curr);
    int r,c;
    while (!que.empty()) {
      tie(r, c) = que.front(); que.pop();
      for (int k = 0; k < 8; ++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (nr >= N || nc >= N || nr < 0 || nc < 0) continue;
        if (dist[nr][nc] != -1) continue;

        dist[nr][nc] = dist[r][c] + 1;
        que.push({ nr, nc });
      }
    }

    cout << dist[dest.first][dest.second] << '\n';
  }

  return 0;
}