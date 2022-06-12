#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <array>
#include <memory.h>

using namespace std;

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int cnts[3] = { 0, 0, 0 };
  array<string, 3> start;

  for (int i = 0; i < 3; ++i) {
    int strLen;
    cin >> strLen;

    if (strLen == 0) {
      start[i] = "";
      continue;
    }

    cin >> start[i];

    for (int j = 0; j < strLen; ++j) {
      ++cnts[start[i][j] - 'A'];
    }
  }

  queue<array<string, 3>> que;
  que.push(start);
  map<array<string, 3>, int> dist;
  dist[start] = 0;

  while (!que.empty()) {
    array<string, 3> currentState = que.front(); que.pop();

    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (i == j) continue;
        // src 문자열이 빈 경우 패스
        if (currentState[i].length() == 0) continue;
        array<string, 3> nextState(currentState);
        nextState[j].push_back(nextState[i].back());
        nextState[i].pop_back();

        if (dist.count(nextState) == 0) {
          dist[nextState] = dist[currentState] + 1;
          que.push(nextState);
        }
      }
    }
  }

  array<string, 3> dest;

  // 도착 지점을 만들자.
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < cnts[i]; ++j) {
      dest[i] += (char) ('A' + i);
    }
  }

  cout << dist[dest] << "\n";

  return 0;
}
