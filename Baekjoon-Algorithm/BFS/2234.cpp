#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <memory.h>

using namespace std;

int M, N;
int groupIdx = 0;

int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};

void bfs(vector<vector<int>>& map, vector<vector<int>>& groups, unordered_map<int, int>& areaMap, int sr, int sc) {
  queue<pair<int, int>> q;
  groups[sr][sc] = groupIdx;

  q.push({ sr, sc });

  int area = 0;

  int r = sr;
  int c = sc;

  while (!q.empty()) {
    tie(r, c) = q.front(); q.pop();
    ++area;

    for (int k = 0; k < 4; ++k) {
      if (map[r][c] & (1 << k)) continue;
      int nr = r + dr[k];
      int nc = c + dc[k];

      if (nr < 0 || nc < 0 || nr >= M || nc >= N) continue;
      if (groups[nr][nc] != -1) continue;
      groups[nr][nc] = groupIdx;

      q.push({ nr, nc });
    }
  }

  // cout << "sr: " << sr << "\n";
  // cout << "sc: " << sc << "\n";
  // cout << "area: " << area << "\n";
  areaMap.insert({ groupIdx, area });
  groupIdx++;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  vector<vector<int>> map(M, vector<int>(N));
  // i, j 번째의 위치한 블록이 어떤 그룹에 속하는가?
  vector<vector<int>> groups(M, vector<int>(N, -1));
  // 그룹 인덱스, 넓이
  unordered_map<int, int> areaMap;

  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (groups[i][j] == -1) {
        bfs(map, groups, areaMap, i, j);
      }
    }
  }

  cout << groupIdx << "\n";

  int groupMaxArea = max_element(
    areaMap.begin(),
    areaMap.end(),
    [] (auto& a, auto& b) -> bool { 
      return a.second < b.second;
    }
  )->second;

  cout << groupMaxArea << "\n";

  int maxSum = 0;

  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N ; ++j) {
      // k 방향에 벽을 포함하는 경우 빼 보자.
      for (int k = 0; k < 4; ++k) {
        int nr = i + dr[k];
        int nc = j + dc[k];
        if (nr < 0 || nc < 0 || nr >= M || nc >= N) continue;
        // 당연히 벽이 있는 상태여야 없앨 수 있음.
        if (map[i][j] & (1 << k)) {
          // 양쪽이 같은 그룹인 경우
          if (groups[i][j] == groups[nr][nc]) continue;

          int sum = areaMap[groups[i][j]] + areaMap[groups[nr][nc]];
          if (maxSum < sum) {
            maxSum = sum;
          }
        }
      }
    }
  }

  cout << maxSum << "\n";

  return 0;
}