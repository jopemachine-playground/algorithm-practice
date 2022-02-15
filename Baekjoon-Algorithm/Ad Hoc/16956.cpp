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

using namespace std;

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

// 양과 늑대가 붙어 있는지 검사.
bool check(vector<vector<char>>& map) {
  for (int i = 0; i < map.size() ; ++i) {
    for (int j = 0; j < map[i].size(); ++j) {
      for (int k = 0; k < 4; ++k) {
        int nr = i + dr[k];
        int nc = j + dc[k];

        if (nr >= map.size() || nr < 0 || nc >= map[0].size() || nc < 0) continue;

        if (
          (map[i][j] == 'S' && map[nr][nc] == 'W') ||
          (map[i][j] == 'W' && map[nr][nc] == 'S')
        ) {
          return false;
        }
      }
    }
  }

  return true;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int R, C;
  cin >> R >> C;
  vector<vector<char>> map(R, vector<char>(C));
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> map[i][j];
    }
  }

  if (!check(map)) {
    cout << 0 << "\n";
    return 0;
  }

  cout << 1 << "\n";

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (map[i][j] == '.') cout << 'D';
      if (map[i][j] == 'S') cout << 'S';
      if (map[i][j] == 'W') cout << 'W';
      if (map[i][j] == 'D') cout << 'D';
    }
    cout << "\n";
  }

  return 0;
}