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

class Queue {
public:
  int begin;
  int end;
  vector<int> nums;

  Queue() {
    begin = 0;
    end = 0;
  }

  void push(int num) {
    nums.push_back(num);
    ++end;
  }

  void pop() {
    if (begin == end) {
      return;
    }

    int ret = nums[begin];
    ++begin;

    if (begin == end) {
      begin = 0;
      end = 0;
      nums.clear();
    }
  }

  int front() {
    if (begin == end) return -1;
    return nums[begin];
  }

  int back() {
    if (begin == end) return -1;
    return nums[end - 1];
  }

  bool isEmpty() {
    return begin == end;
  }

  int size() {
    return end - begin;
  }
};

int solve() {
  _FASTIOS;
  int N;
  cin >> N;
  Queue que;

  while (N--) {
    string str;
    cin >> str;
    if (str == "push") {
      int num;
      cin >> num;
      que.push(num);
    }
    else if (str == "pop") {
      if (!que.size()) cout << -1 << "\n";
      else {
        cout << que.front() << "\n";
        que.pop();
      }
    }
    else if (str == "empty") {
      cout << (que.isEmpty() ? 1 : 0) << "\n";
    }
    else if (str == "front") {
      cout << que.front() << "\n";
    }
    else if (str == "back") {
      cout << que.back() << "\n";
    }
    else if (str == "size") {
      cout << que.size() << "\n";
    }
  }
  return 0;
}