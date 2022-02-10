// 백준 알고리즘 강의 중급
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
  int N, M;
  cin >> N >> M;

  set<string> setA;

  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    setA.insert(str);
  }

  vector<string> ans;
  for (int i = 0; i < M; ++i) {
    string str;
    cin >> str;
    if (setA.count(str)) {
      ans.push_back(str);
    }
  }

  sort(ans.begin(), ans.end());

  cout << ans.size() << "\n";
  for (auto& name : ans) {
    cout << name << "\n";
  }

  return 0;
}