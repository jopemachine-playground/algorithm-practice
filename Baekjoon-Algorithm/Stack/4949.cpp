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

// int main() {
int solve() {
  _FASTIOS;
  string str;
  while (true) {
    getline(cin, str);

    if (str == ".") break;
    stack<char> stk;

    bool res = true;
    for (int i = 0; i < str.length(); ++i) {
      if (str[i] == '(' || str[i] == '[') {
        stk.push(str[i]);
      }
      if (str[i] == ')') {
        if (stk.size() > 0 && stk.top() == '(') stk.pop();
        else {
          res = false;
          break;
        }
      }
      if (str[i] == ']') {
        if (stk.size() > 0 && stk.top() == '[') stk.pop();
        else {
          res = false;
          break;
        }
      }
    }

    if (!stk.empty()) res = false;

    cout << (res ? "yes" : "no") << "\n";
  }
  return 0;
}