// 백준 알고리즘 강좌 중급
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve () {
  int N;
  cin >> N;
  vector<vector<int>> map(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> map[i][j];
    }
  }

  // N개 배열에서 N/2개 만큼 1이고, 나머지 0으로 팀을 나타내면, 최대 연산량 (20! / 10! * 10!)이 된다 
  vector<int> isFirstTeam(N);
  for (int i = N / 2; i < N; ++i) {
    isFirstTeam[i] = 1;
  }

  int ans = 2147483647;
  do {
    vector<int> first, second;
    for (int i = 0; i < N; ++i) {
      if (isFirstTeam[i] == 0) {
        first.push_back(i);
      } else {
        second.push_back(i);
      }
    }
    int one = 0;
    int two = 0;

    for (int i = 0; i < N / 2; ++i) {
      for (int j = 0; j < N / 2; ++j) {
        if (i == j) continue;
        one += map[first[i]][first[j]];
        two += map[second[i]][second[j]];
      }
    }
    int diff = one - two;
    if (diff < 0) diff = -diff;
    if (ans > diff) ans = diff;
  } while (next_permutation(isFirstTeam.begin(), isFirstTeam.end()));

  cout << ans << "\n";
  return 0;
}