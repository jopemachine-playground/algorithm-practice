// 백준 알고리즘 중급
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
#include <cmath>
#include <cassert>

using namespace std;

#define debug if constexpr (LOCAL) cout
#define endl '\n'

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

#define ll long long

vector<int> getMatchingTbl (string needle) {
  int M = needle.size();
  vector<int> pi(M);
  pi[0] = 0;
  int j = 0;
  for (int i = 1; i < M; ++i) {
    while (j > 0 && needle[i] != needle[j]) {
      j = pi[j - 1];
    }
    if (needle[i] == needle[j]) {
      pi[i] = ++j;
    } else {
      pi[i] = 0;
    }
  }
  return pi;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  vector<int> cnts(s.size() + 1);
  auto pi = getMatchingTbl(s);

  // 일단 세고..
  for (int i = 0; i < s.length(); ++i) {
    ++cnts[pi[i]];
  }

  // 이전 거에 누적해주자.
  for (int i = s.length(); i > 0; --i) {
    cnts[pi[i - 1]] += cnts[i];
  }
  
  // for (int i = 0; i < s.size(); ++i) {
  //   cout << cnts[i] << " ";
  // }

  vector<pair<int, int>> ans;
  for (int i = s.length(); i > 0; i = pi[i - 1]) {
    ans.push_back({ i , cnts[i] + 1 });
  }

  reverse(ans.begin(), ans.end());

  cout << ans.size() << "\n";
  for (auto& p : ans) {
    cout << p.first << ' ' << p.second << "\n";
  }

  return 0;
}