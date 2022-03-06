/*
==============================+===============================================================
@ Title : 집합
@ Desc :
@ Ref :
==============================+===============================================================
*/

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
#define ll long long
#define pii pair<int, int>

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

int solve() {
  _FASTIOS;
  int M;
  cin >> M;
  int S = 0;

  for (int i = 0; i < M; ++i) {
    string command;
    cin >> command;
    int arg;

    if (command == "check") {
      cin >> arg;
      if (S & (1 << arg)) {
        cout << 1 << "\n";
      }
      else {
        cout << 0 << "\n";
      }
    }

    if (command == "add") {
      cin >> arg;
      S |= (1 << arg);
    }
    if (command == "remove") {
      cin >> arg;
      // if (S & (1 << arg)) {
      //   S -= (1 << arg);
      // }
      S &= ~(1 << arg);
    }
    if (command == "toggle") {
      cin >> arg;
      S ^= (1 << arg);
    }
    if (command == "all") {
      S = (1 << 21) - 1;
    }
    if (command == "empty") {
      S = 0;
    }
  }
  return 0;
}