#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <tuple>
#include <algorithm>
#include <memory.h>

using namespace std;

int K, W, H;

int dr[] = {0,0,1,-1,2,1,-2,-1,2,1,-2,-1};
int dc[] = {1,-1,0,0,1,2,-1,-2,-1,-2,1,2};
bool isHorseMove[] = {false,false,false,false,true,true,true,true,true,true,true,true};
const int MAX_SAFE_INT = 2000000000;

int map[200][200];
int dist[200][200][31];

void bfs(int r, int c, int k) {
  queue<tuple<int,int,int>> q;
  q.push(make_tuple(r, c, k));
  dist[0][0][k] = 0;

  while(!q.empty()) {
    tie(r, c, k) = q.front(); q.pop();

    for (int dir = 0; dir < 12; ++dir) {
      int nr = r + dr[dir];
      int nc = c + dc[dir];
      int nk = isHorseMove[dir] ? k - 1 : k;

      if (nr >= H || nc >= W || nr < 0 || nc < 0) continue;
      if (dist[nr][nc][nk] != -1) continue;
      if (map[nr][nc] == 1) continue;
      if (isHorseMove[dir] && nk < 0) continue;

      q.push(make_tuple(nr, nc, nk));
      dist[nr][nc][nk] = dist[r][c][k] + 1;
    }
  }
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> K >> W >> H;

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> map[i][j];
    }
  }

  memset(dist, -1, sizeof(dist));

  bfs(0, 0, K);

  int result = MAX_SAFE_INT;
  for (int i = 0; i <= K; ++i) {
    if (
      dist[H - 1][W - 1][i] != -1 && 
      dist[H - 1][W - 1][i] < result
    ) {
      result = dist[H - 1][W - 1][i];
    }
  }

  cout << (result == MAX_SAFE_INT ? -1 : result) << "\n";

  return 0;
}