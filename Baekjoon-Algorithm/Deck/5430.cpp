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

int solve() {
  _FASTIOS;
  int T;
  cin >> T;
  while (T--) {
    string command;
    cin >> command;
    int N;
    cin >> N;
    string str;
    cin >> str;
    // cout << str << "\n";
    deque<string> nums;
    string buf = "";

    for (int i = 1; i < str.length() - 1; ++i) {
      if (str[i] == ',') {
        assert(buf != "");
        nums.push_back(buf);
        buf = "";
      } else {
        buf += str[i];
      }
    }

    if (buf != "") {
      nums.push_back(buf);
    }

    // for (int i = 0; i < nums.size(); ++i) {
    //   cout << nums[i] << " ";
    // }

    bool orderIsFront = true;
    bool hasErrorOccured = false;

    for (int i = 0; i < command.length(); ++i) {
      if (command[i] == 'R') {
        orderIsFront = !orderIsFront;
      }

      else if (command[i] == 'D') {
        if (nums.size() == 0) {
          hasErrorOccured = true;
          break;
        }

        if (orderIsFront) {
          nums.pop_front();
        } else {
          nums.pop_back();
        }
      }
    }

    if (hasErrorOccured) {
      cout << "error\n";
      continue;
    }

    cout << "[";
    if (orderIsFront) {
      for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1) {
          cout << ",";
        }
      }
    } else {
      for (int i = nums.size() - 1; i >= 0; --i) {
        cout << nums[i];
        if (i != 0) {
          cout << ",";
        }
      }
    }
    cout << "]\n";
  }

  return 0;
}