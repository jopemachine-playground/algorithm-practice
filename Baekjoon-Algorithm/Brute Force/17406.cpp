// 백준 알고리즘 중급 강의
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ArrRotateInfo {
  int r;
  int c;
  int s;
};

int N, M, K;

// 각 껍질들을 일차원 배열로 바꾸고, 회전한 후 다시 이차원 배열로 바꾼다.
void rotateArray (vector<vector<int>>& map, int row, int col, int size) {
  // 바로 아래에서 시작
  vector<vector<int>> groups;

  // 각 껍질들을 group이라는 일차원 배열로 바꿈.
  for (int s = 1; s <= size; ++s) {
    vector<int> group;
    // (r-s, c-s) -> (r-s, c+s)
    for (int r = row - s, c = col - s; c < col + s; ++c) {
      group.push_back(map[r][c]);
    }
    // (r-s, c+s) -> (r+s, c+s)
    for (int r = row - s, c = col + s; r < row + s; ++r) {
      group.push_back(map[r][c]);
    }
    // (r+s, c+s) -> (r+s, c-s)
    for (int r = row + s, c = col + s; c > col - s; --c) {
      group.push_back(map[r][c]);
    }
    // (r+s, c-s) -> (r-s, c-s)
    for (int r = row + s, c = col - s; r > row - s; --r) {
      group.push_back(map[r][c]);
    }

    groups.push_back(group);
  }

  // 각 일차원 배열들을 회전 시킨 후 복원
  for (int s = 1; s <= size; ++s) {
    auto& group = groups[s - 1];

    // 오른쪽으로 회전 시키기 위해 rbegin 사용 (역방향)
    rotate(group.rbegin(), group.rbegin() + 1, group.rend());
    int index = 0;

    // (r-s, c-s) -> (r-s, c+s)
    for (int r = row - s, c = col - s; c < col + s; ++c) {
      map[r][c] = group[index++];
    }
    // (r-s, c+s) -> (r+s, c+s)
    for (int r = row - s, c = col + s; r < row + s; ++r) {
      map[r][c] = group[index++];
    }
    // (r+s, c+s) -> (r+s, c-s)
    for (int r = row + s, c = col + s; c > col - s; --c) {
      map[r][c] = group[index++];
    }
    // (r+s, c-s) -> (r-s, c-s)
    for (int r = row + s, c = col - s; r > row - s; --r) {
      map[r][c] = group[index++];
    }
  }
}

void printMap (vector<vector<int>>& map) {
  cout << "---------------------" << "\n";
  for (int i = 0; i < map.size(); ++i) {
    for (int j = 0; j < map[0].size(); ++j) {
      cout << map[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "---------------------" << "\n";
}

int calcArrayValue(vector<vector<int>>& map) {
  int res = 2000000000;
  for (int i = 0; i < N; ++i) {
    int sum = 0;
    for (int j = 0; j < M; ++j) {
      sum += map[i][j];
    }
    res = min(res, sum);
  }
  return res;
}

int getRotatedArrayValue (vector<vector<int>> map, vector<ArrRotateInfo>& rotateInfos, vector<int>& rotateOrder) {
  int res = 2000000000;

  for (int i = 0; i < rotateOrder.size(); ++i) {
    int r = rotateInfos[rotateOrder[i]].r;
    int c = rotateInfos[rotateOrder[i]].c;
    int s = rotateInfos[rotateOrder[i]].s;

    rotateArray(map, r, c, s);
    // printMap(map);
  }

  res = min(res, calcArrayValue(map));

  return res;
}

// int main() {
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> K;
  vector<vector<int>> map(N, vector<int>(M));
  for (auto& vec : map) {
    for (int& input: vec) {
      cin >> input;
    }
  }

  vector<ArrRotateInfo> rotateInfos(K);

  vector<int> rotateIdxes(K);
  for (int i = 0; i < K; ++i) {
    rotateIdxes[i] = i;
  }

  for (auto& info : rotateInfos) {
    cin >> info.r >> info.c >> info.s;
    info.r -= 1;
    info.c -= 1;
  }

  int res = 2000000000;

  do {
    res = min(res, getRotatedArrayValue(map, rotateInfos, rotateIdxes));
  } while (next_permutation(rotateIdxes.begin(), rotateIdxes.end()));

  cout << res << "\n";

  return 0;
}