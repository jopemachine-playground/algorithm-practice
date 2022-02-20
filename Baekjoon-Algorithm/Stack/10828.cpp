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

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> stk;

  for (int i = 0; i < N; ++i) {
    string opr;
    cin >> opr;
    if (opr == "push") {
      int num;
      cin >> num;
      stk.push_back(num);
    }
    else if (opr == "top") {
      if (stk.size() == 0) cout << -1 << "\n";
      else cout << stk[stk.size() - 1] << "\n";
    }
    else if (opr == "size") {
      cout << stk.size() << "\n";
    }
    else if (opr == "pop") {
      if (stk.size() == 0) cout << -1 << "\n";
      else {
        cout << stk[stk.size() - 1] << "\n";
        stk.pop_back();
      }
    }
    else if (opr == "empty") {
      cout << (stk.size() == 0 ? 1 : 0) << "\n";
    }
  }
  return 0;
}