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
  string str, targetStr;
  cin >> str >> targetStr;

  stack<pair<int, int>> stk;

  vector<bool> removedIdxes(str.size(), false);

  if (targetStr.size() == 1) {
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == targetStr[0]) {
        removedIdxes[i] = true;
      }
    }
  } else {
    for (int i = 0; i < str.size(); ++i) {
      if (targetStr[0] == str[i]) {
        stk.push({ i, 0 });
      } else if (stk.size() > 0) {
        if (targetStr[stk.top().second + 1] == str[i]) {
          stk.push({ i, stk.top().second + 1 });

          if (targetStr.back() == str[i]) {
            int len = targetStr.size();
            while (len-- > 0) {
              removedIdxes[stk.top().first] = true;
              stk.pop();
            }
          }
        } else {
          while(stk.size() != 0) stk.pop();
        }
      }
    }
  }

  bool print = false;
  for (int i = 0; i < str.size(); ++i) {
    if (!removedIdxes[i]) {
      print = true;
      cout << str[i];
    }
  }

  if (!print) {
    cout << "FRULA" << "\n";
  }

  return 0;
}