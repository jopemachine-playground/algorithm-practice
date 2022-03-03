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

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

#define ll long long
#define pii pair<int, int>

int map[51][51];
int dist[51][51];
int N, M;

int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};

bool isInvalidRange(int r, int c) {
  return r < 0 || c < 0 || r >= N || c >= N;
}

void bfs(vector<pii>& starts) {
  queue<pii> que;
  memset(dist, -1, sizeof dist);

  int r, c;
  for (int i = 0; i < starts.size(); ++i) {
    tie(r, c) = starts[i];
    que.push({ r, c });
    dist[r][c] = 0;
  }

  while (!que.empty()) {
    tie(r, c) = que.front();
    que.pop();

    for (int k = 0; k < 4; ++k) {
      int nr = r + dr[k];
      int nc = c + dc[k];
      if (isInvalidRange(nr, nc)) continue;
      if (dist[nr][nc] != -1) continue;
      if (map[nr][nc] == 1) continue;

      dist[nr][nc] = dist[r][c] + 1;
      que.push({ nr, nc });
    }
  }
}

// 2: 바이러스가 놓일 수 있는 위치
// =>
// 3: 놓은 바이러스
// 4: 놓지 않은 바이러스
void markVirus(int i) {
  int cnt = 0;
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < N; ++c) {
      if (map[r][c] != 0 && map[r][c] != 1) {
        if (i & (1 << cnt)) {
          map[r][c] = 3;
        } else {
          map[r][c] = 4;
        }

        ++cnt;
      }
    }
  }
}

void print() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << map[i][j] << ' ';
    }
    cout << "\n";
  }
  cout << "\n";
}

void printDistMap() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << dist[i][j] << ' ';
    }
    cout << "\n";
  }
  cout << "\n";
}

int getMinTime() {
  int maxVal = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (map[i][j] != 1) {
        if (dist[i][j] == -1) return -1;
        maxVal = max(maxVal, dist[i][j]);
      }
    }
  }
  return maxVal;
}

vector<pii> findStarts() {
  vector<pii> starts;
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < N; ++c) {
      if (map[r][c] == 3) {
        starts.push_back({ r, c });
      }
    }
  }
  return starts;
}

int solve() {
  _FASTIOS;
  cin >> N >> M;

  int twoCnt = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> map[i][j];
      if (map[i][j] == 2) ++twoCnt;
    }
  }

  int res = 2e9;
  for (int i = 0; i < (1 << twoCnt); ++i) {
    int cnt = 0;
    for (int j = 0; j < twoCnt; ++j) {
      if (i & (1 << j)) {
        ++cnt;
      }
    }

    // 어쨌든 M개는 일단 골라야 최대한 빠르게 바이러스가 퍼질테니, M개 이하 골랐다면 패스.
    // M개 이상 고를 수 없으니 그 이상도 패스.
    if (cnt != M) continue;

    markVirus(i);
    // print();

    auto starts = findStarts();

    bfs(starts);

    // printDistMap();

    int time = getMinTime();

    if (res > time && time != -1) {
      res = time;
    }
  }

  cout << (res == 2e9 ? -1 : res) << "\n";

  return 0;
}