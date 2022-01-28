#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int main () {
  int N;
  cin >> N;

  vector<pair<int, int>> vec(N);

  for (int i = 0; i < N; ++i) {
    int d, p;
    scanf("%d %d", &p, &d);
    vec.push_back({ p, d });
  }

  // 걸리는 시간에 내림차순으로 정렬
  sort(vec.begin(), vec.end(), [](auto u, auto v) {
    return u.second > v.second;
  });

  priority_queue<int> pq;
  int ans = 0;
  int idx = 0;

  for (int i = 10000; i >= 1; --i) {
    while (idx < N && vec[idx].second == i) {
      pq.push(vec[idx].first);
      idx++;
    }

    if (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
  }

  cout << ans << "\n";
}