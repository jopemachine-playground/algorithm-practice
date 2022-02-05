// 백준 알고리즘 강의 중급
#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> group;
vector<int> groupSize;

int groupSizeIdx = 0;
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

inline bool checkInvalidRange(int r, int c) {
  return r >= N || c >= M || r < 0 || c < 0;
}

void bfs(int r, int c) {
  ++groupSizeIdx;

  int groupCnt = 1;
  queue<pair<int,int>> que;

  que.push({ r, c });
  group[r][c] = groupSizeIdx;

  while(que.size() > 0) {
    tie(r, c) = que.front(); que.pop();

    for (int k = 0; k < 4; ++k) {
      int nr = r + dr[k];
      int nc = c + dc[k];

      if (checkInvalidRange(nr, nc)) continue;
      if (map[nr][nc] != 1) continue;
      // 방문한 적 있음
      if (group[nr][nc] != -1) continue;
      group[nr][nc] = groupSizeIdx;
      que.push({ nr, nc });
      ++groupCnt;
    }
  }

  groupSize[groupSizeIdx] = groupCnt;
}

// int main() {
int solve() {
  cin >> N >> M;
  map = vector<vector<int>>(N, vector<int>(M));
  group = vector<vector<int>>(N, vector<int>(M, -1));
  groupSize = vector<int>((N + 1) * (M + 1));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (group[i][j] == -1 && map[i][j] == 1) {
        bfs(i, j);
      }
    }
  }

  int result = 0;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (map[i][j] == 0) {
        // 인접한 그룹이 같은 그룹일 수도 있기 때문에 그냥 사이즈 구해서 더해버리면 안 된다.
        // 인접한 그룹들의 인덱스를 중복 없이 구하고 사이즈를 더해주자.
        set<int> nearGroupIdxes;

        for (int k = 0; k < 4; ++k) {
          int nr = i + dr[k];
          int nc = j + dc[k];
          if (checkInvalidRange(nr, nc)) continue;

          if (map[nr][nc] == 1) {
            int groupIdx = group[nr][nc];
            nearGroupIdxes.insert(groupIdx);
          }

          int sum = 0;
          for (int groupIdx : nearGroupIdxes) {
            sum += groupSize[groupIdx];
          }
          // 하나 더해줘야 함.
          sum += 1;
          if (result < sum) result = sum;
        }
      }
    }
  }

  cout << result << "\n";

  return 0;
}