/*
==============================+===============================================================
@ Title : 두 용액
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
  int N;
  cin >> N;
  vector<int> nums(N);
  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
  }
  int left = 0, right = N - 1;
  pii ans;
  int zeroClose = 2e9;
  sort(nums.begin(), nums.end());

  while (left < right) {
    int sum = nums[left] + nums[right];

    if (zeroClose > abs(sum)) {
      zeroClose = abs(sum);
      ans.first = nums[left];
      ans.second = nums[right];
    }

    if (sum > 0) {
      --right;
    }
    else {
      ++left;
    }
  }

  cout << ans.first << " " << ans.second;
  return 0;
}