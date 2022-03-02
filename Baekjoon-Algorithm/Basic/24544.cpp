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
  int N;
  cin >> N;
  vector<int> nums(N);
  vector<bool> checked(N);

  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
  }

  for (int i = 0; i < N; ++i) {
    int check;
    cin >> check;
    if (check == 1) {
      checked[i] = true;
    } else {
      checked[i] = false;
    }
  }

  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < N; ++i) {
    sum1 += nums[i];
    if (!checked[i]) {
      sum2 += nums[i];
    }
  }

  cout << sum1 << "\n";
  cout << sum2 << "\n";
  return 0;
}