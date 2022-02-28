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

using namespace std;

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

  string S;
  cin >> S;
  vector<int> pi = getMatchingTbl(S);

  // for (int i = 0; i < pi.size(); ++i) {
  //   cout << pi[i] << " ";
  // }

  vector<int> cnt(S.length() + 1, 0);

  // fail 함수의 정의 상 fail[i]값이 1 이상이면, 0부터 i까지의 문자열이
  // 접미사이면서 접두사를 만족하게 된다.
  // 카멜레온 문자열이 되려면 그 외에 한 번 더 나와야 한다.
  // 따라서, 마지막에 나오는 fail[N]을 제외하고 fail 값을 카운트
  // 했을 때, cnt가 1 이상이면 바로 답이다.
  // cnt가 0이라면 pi에 한 번만 나온 경우, 이전 pi 값을 검사한다.
  // 안 나온 경우 0이 되면서 종료한다.
  for (int i = 0; i < S.length() - 1; ++i) {
    cnt[pi[i]]++;
  }

  // for (int i = 0; i < cnt.size(); ++i) {
  //   cout << cnt[i] << " ";
  // }

  for (int i = S.length(); i != 0; i = pi[i - 1]) {
    // cout << "i: " << i << "\n";
    // cout << pi[i - 1] << "\n";
    if (cnt[i] >= 1) {
      cout << S.substr(0, i) << "\n";
      return 0;
    }
  }

  cout << -1 << "\n";

  return 0;
}