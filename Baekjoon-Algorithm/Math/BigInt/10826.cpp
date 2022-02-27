// Ref:: https://www.acmicpc.net/board/view/38192
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

string reverse(string str) {
  string res;
  for (int i = str.size() - 1; i >= 0; --i) {
    res.push_back(str[i]);
  }
  return res;
}

class BigInt {
public:
  string value;
  BigInt() {};
  BigInt(string str): value(str) {};

  // 두 수를 뒤집어서 맨 뒤에 숫자부터 하나씩 차근차근 더해준다.
  // (맨 뒤가 up이 0이기 때문에 맨 뒤에서 시작해야 한다.)
  // 이 부분을 두 부분으로 나누어 진행해야 한다.
  // 1. 길이가 서로 겹치는 부분을 계산해주고, 2. 길이가 남은 부분을 계산해준다.
  BigInt operator+ (const BigInt& rhs) {
    string s1 = reverse(value);
    string s2 = reverse(rhs.value);
    int minLen = min(s1.size(), s2.size());
    int maxLen = max(s1.size(), s2.size());

    int i;
    string res;
    int up = 0;

    // s1, s2를 뒤집어 길이가 겹치는 부분을 계산
    for (i = 0; i < minLen; ++i) {
      int k = (s1[i] - '0') + (s2[i] - '0') + up;
      up = k / 10;
      res.push_back((char) (k % 10 + '0'));
    }

    // 길이가 남는 부분 계산.
    for (; i < maxLen; ++i) {
      if (s1.size() > s2.size()) {
        int k = s1[i] - '0' + up;
        up = k / 10;
        res.push_back((char) (k % 10 + '0'));
      } else {
        int k = s2[i] - '0' + up;
        up = k / 10;
        res.push_back((char) (k % 10 + '0'));
      }
    }

    if (up) res.push_back('1');
    return BigInt(reverse(res));
  }
};

ostream& operator<<(ostream& os, const BigInt i) {
  os << i.value;
  return os;
};

BigInt dp[10001];

BigInt big_fib(int n) {
  if (n == 0 || n == 1) return BigInt(to_string(n));
  // 초기화된 BigInt라면 (값이 계산된 경우) 길이가 1 이상이어야 함.
  if (dp[n].value.size() > 0) return dp[n];
  return dp[n] = big_fib(n - 1) + big_fib(n - 2);
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  cout << big_fib(N) << "\n";
  return 0;
}