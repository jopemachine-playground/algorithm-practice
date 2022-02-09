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

vector<int> getMatchingTbl (const string& needle) {
  int needleSize = needle.size();
  vector<int> res(needleSize, 0);
  int j = 0;
  for (int i = 1; i < needleSize; ++i) {
    while (j > 0 && needle[i] != needle[j]) {
      j = res[j - 1];
    }

    if (needle[i] == needle[j]) {
      res[i] = ++j;
    }
  }

  return res;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  string str;
  cin >> str;

  int ans = -1;
  for (int i = 0; i < str.size(); ++i) {
    auto tbl = getMatchingTbl(str);

    for (int j = 0; j < tbl.size(); ++j) {
      if (ans < tbl[j]) {
        ans = tbl[j];
      }
    }

    rotate(str.begin(), str.begin() + 1, str.end());
  }

  cout << ans << "\n";

  return 0;
}