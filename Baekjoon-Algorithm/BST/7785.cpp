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
  set<string> set;

  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    string name, action;
    cin >> name >> action;
    if (action == "enter") {
      set.insert(name);
    } else {
      set.erase(set.find(name));
    }
  }

  // set은 자동으로 사전 순으로 정렬해서 저장된다.
  // 사전 순의 역순으로 출력하라고 했으니 rbegin에서 부터 rend까지 돌면 된다.
  for (auto it = set.rbegin(); it != set.rend(); it++) {
    cout << *it << '\n';
  }

  return 0;
}