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

using namespace std;

vector<int> getMatchingTbl(string needle) {
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

vector<int> kmp(string haystack, string needle) {
  vector<int> res;
  int H = haystack.size();
  int M = needle.size();

  auto pi = getMatchingTbl(needle);

  int j = 0;
  for (int i = 0; i < H; ++i) {
    while (j > 0 && haystack[i] != needle[j]) {
      j = pi[j - 1];
    }
    if (haystack[i] == needle[j]) {
      // 바늘 문자열을 찾았다!
      if (j == M - 1) {
        res.push_back(i - M + 1);
        j = pi[j];
      } else {
        ++j;
      }
    }
  }
  return res;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string A, B;
  cin >> A >> B;
  
  // B를 반복시키고 이 중 A가 몇 번 등장하는지 찾으면 된다.
  string needle = A;
  string haystack = B + B;
  haystack.pop_back();
  cout << kmp(haystack, needle).size() << "\n";

  return 0;
}