// 백준 알고리즘 강의 중급
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;

int solve () {
  cin >> N >> M;

  vector<vector<char>> map(N, vector<char>(M));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> map[i][j];
    }
  }

  int areaProductMax = 0;

  for (int x1 = 0; x1 < N; ++x1) {
    for (int y1 = 0; y1 < M; ++y1) {
      // 아래처럼 map을 매번 복사해도 되긴 하지만..
      // vector<vector<char>> thisMap = map;

      for (int s1 = 0; ; ++s1) {
        if (x1 - s1 < 0 || x1 + s1 >= N) break;
        if (y1 - s1 < 0 || y1 + s1 >= M) break;
        // 이 문제의 경우 첫 번째 넓이 찾을 때 최대한으로 찾는게 
        // 최적해가 아닌 경우가 있기 때문에 꼭 이렇게 모든 경우를 다 돌아서 풀어줘야 된다는 게 포인트인 듯..
        if (map[x1 - s1][y1] != '#' || map[x1 + s1][y1] != '#') break;
        if (map[x1][y1 - s1] != '#' || map[x1][y1 + s1] != '#') break;

        map[x1 - s1][y1] = '*';
        map[x1][y1 - s1] = '*';
        map[x1 + s1][y1] = '*';
        map[x1][y1 + s1] = '*';

        for (int x2 = 0; x2 < N; ++x2) {
          for (int y2 = 0; y2 < M; ++y2) {
            for (int s2 = 0; ; ++s2) {
              if (x2 - s2 < 0 || x2 + s2 >= N) break;
              if (y2 - s2 < 0 || y2 + s2 >= M) break;

              if (map[x2 - s2][y2] != '#' || map[x2 + s2][y2] != '#') break;
              if (map[x2][y2 - s2] != '#' || map[x2][y2 + s2] != '#') break;

              int area1 = (4 * s1 + 1);
              int area2 = (4 * s2 + 1);
              if (areaProductMax < area1 * area2) areaProductMax = area1 * area2;
            }
          }
        }
      }

      // 이렇게 백트랙킹 하고 나서 돌려주는 것 처럼 구현하면 map을 매번 복사 안 해도 된다!
      for (int s1 = 0; ; ++s1) {
        if (x1 - s1 < 0 || x1 + s1 >= N) break;
        if (y1 - s1 < 0 || y1 + s1 >= M) break;
        if (map[x1 - s1][y1] != '*' || map[x1 + s1][y1] != '*') break;
        if (map[x1][y1 - s1] != '*' || map[x1][y1 - s1] != '*') break;
        map[x1 - s1][y1] = '#';
        map[x1 + s1][y1] = '#';
        map[x1][y1 + s1] = '#';
        map[x1][y1 - s1] = '#';
      }
    }
  }

  cout << areaProductMax << '\n';

  return 0;
}