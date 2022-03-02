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
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
#define endl '\n'

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

#define ll long long

string reverse(string str) {
  string ret = "";
  for (int i = 0; i < str.length(); ++i) {
    ret.push_back(str[str.length() - i - 1]);
  }
  return ret;
}

class BigInt {
public:
  string s;
  BigInt() {};
  BigInt(string str): s(str) {};
  BigInt operator+ (const BigInt& rhs) {
    string ret = "";
    string s1 = reverse(s);
    string s2 = reverse(rhs.s);

    int minLen = s1.length() < s2.length() ? s1.length() : s2.length();
    int up = 0;

    for (int i = 0; i < minLen; ++i) {
      int sum = (s1[i] - '0') + (s2[i] - '0') + up;
      ret.push_back((char) sum % 10 + '0');
      up = (sum / 10);
    }

    int maxLen = s1.length() + s2.length() - minLen;

    for (int i = minLen; i < maxLen; ++i) {
      if (s1.length() > s2.length()) {
        int sum = (s1[i] - '0') + up;
        ret.push_back((char) sum % 10 + '0');
        up = (sum / 10); 
      } else {
        int sum = (s2[i] - '0') + up;
        ret.push_back((char) sum % 10 + '0');
        up = (sum / 10); 
      }
    }

    if (up == 1) ret.push_back('1');

    return BigInt(reverse(ret));
  }
};

ostream& operator<<(ostream& os, const BigInt i) {
  os << i.s;
  return os;
}

int solve() {
  _FASTIOS;
  string A, B;
  cin >> A >> B;
  cout << BigInt(A) + BigInt(B) << "\n";
  return 0;
}