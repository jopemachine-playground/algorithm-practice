// 백준 알고리즘 중급
#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <tuple>
#include <algorithm>
#include <memory.h>

using namespace std;

int N;

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

// 그냥은 BFS로 못 푸니 (다익스트라, 0-1 BFS로 풀어도 됨)
// 1차원으로 그래프를 변형하면 풀 수 있다.

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> N;

  vector<string> map(N);
  // i, j 위치에 있는 거울의 번호 (1차원 배열의 인덱스)
  vector<vector<int>> mirIdxes(N, vector<int>(N));
  // 인덱스에 따른 거울의 위치
  vector<pair<int, int>> mirrors;

  int startIdx = -1, endIdx = -1;

  for (int i = 0; i < N; ++i) {
    cin >> map[i];
    for (int j = 0; j < N; ++j) {
      // 출발점, 시작점도 미러에 포함시켜 찾을 것임.
      if (map[i][j] == '#') {
        // 여태까지 발견한 거울들의 갯수를 넣어주면 인덱스를 찾아놓을 수 있다.
        if (startIdx == -1) {
          startIdx = mirrors.size();
        } else {
          endIdx = mirrors.size();
        }

        mirIdxes[i][j] = mirrors.size();
        mirrors.push_back({i, j});
      } else if (map[i][j] == '!') {
        mirIdxes[i][j] = mirrors.size();
        mirrors.push_back({i, j});
      }
    }
  }

  int mirrorCnts = mirrors.size();

  // i에서 j 거울로 이동할 수 있는지를 나타내는 1차원 배열을 생성
  vector<vector<bool>> canMove(mirrorCnts, vector<bool>(mirrorCnts, false));

  for (int i = 0; i < mirrorCnts; ++i) {
    for (int k = 0; k < 4; ++k) {
      int r = mirrors[i].first + dr[k];
      int c = mirrors[i].second + dc[k];

      while (0 <= r && r < N && 0 <= c && c < N) {
        if (map[r][c] == '*') break;
        if (map[r][c] == '!' || map[r][c] == '#') {
          canMove[i][mirIdxes[r][c]] = true;
        }
        r += dr[k];
        c += dc[k];
      }
    }
  }

  queue<int> q;
  vector<int> dist(mirrorCnts, -1);
  // 처음에 찾아놓았던 시작점의 인덱스를 넣는다.
  q.push(startIdx);

  dist[startIdx] = 0;

  while (!q.empty()) {
    int idx = q.front(); q.pop();
    for (int next = 0; next < mirrorCnts; ++next) {
      if (canMove[idx][next] && dist[next] == -1) {
        dist[next] = dist[idx] + 1;
        q.push(next);
      }
    }
  }

  cout << dist[endIdx] - 1 << "\n";

  return 0;
}