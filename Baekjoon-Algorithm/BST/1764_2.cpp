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

  map<string, int> dict;

  for (int i = 0; i < N; ++i) {
    string name;
    cin >> name;
    dict[name] |= 1;
  }

  for (int i = 0; i < M; ++i) {
    string name;
    cin >> name;
    dict[name] |= 2;
  }

  vector<string> ans;

  // dict를 순회하면 알아서 키의 사전순으로 돌게 됨.
  for (auto& p : dict) {
    // 둘 다 포함되면 3
    if (p.second == 3) {
      ans.push_back(p.first);
    }
  }

  cout << ans.size() << "\n";
  for (auto& name : ans) {
    cout << name << "\n";
  }

  return 0;
}