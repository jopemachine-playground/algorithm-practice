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

using namespace std;

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<pair<int, int>> res(N);
  for (int i = 0; i < N; ++i) {
    cin >> res[i].second >> res[i].first;
  }

  sort(res.begin(), res.end());

  for (int i = 0; i < N; ++i) {
    cout << res[i].second << " " << res[i].first << "\n";
  }

  return 0;
}