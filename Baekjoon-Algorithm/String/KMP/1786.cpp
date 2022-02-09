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

vector<int> getPartialMatchTable(string needle) {
  int needleSize = needle.size();
  vector<int> partialMatchTbl(needleSize, 0);
  int j = 0;

  for (int i = 1; i < needleSize; ++i) {
    while (j > 0 && needle[i] != needle[j]) {
      j = partialMatchTbl[j - 1];
    }
    if (needle[i] == needle[j]) {
      partialMatchTbl[i] = ++j;
    }
  }

  return partialMatchTbl;
}

vector<int> kmp(string haystack, string needle) {
  auto matchTbl = getPartialMatchTable(needle);
  vector<int> ans;
  int needleSize = needle.size();
  int j = 0;

  for (int i = 0; i < haystack.size(); ++i) {
    while (j > 0 && haystack[i] != needle[j]) {
      j = matchTbl[j - 1];
    }

    if (haystack[i] == needle[j]) {
      if (j == needleSize - 1) {
        ans.push_back(i - needleSize + 1);
        j = matchTbl[j];
      } else {
        ++j;
      }
    }
  }

  return ans;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  string T, P;
  getline(cin, T);
  getline(cin, P);

  auto matched = kmp(T, P);
  cout << matched.size() << "\n";

  for (auto idx : matched) {
    cout << idx + 1 << " ";
  }

  cout << "\n";

  return 0;
}