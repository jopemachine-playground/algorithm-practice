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

  int N;
  cin >> N;
  vector<int> nums(N);
  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
  }

  vector<int> freq(1e6 + 1, 0);

  for (int i = 0; i < N; ++i) {
    ++freq[nums[i]];
  }

  vector<int> NGF(N);
  stack<int> stk;

  for (int i = N - 1; i >= 0; --i) {
    while (!stk.empty() && (freq[stk.top()] <= freq[nums[i]])) {
      stk.pop();
    }

    if (stk.empty()) {
      NGF[i] = -1;
    } else {
      NGF[i] = stk.top();
    }

    stk.push(nums[i]);
  }

  for (int i = 0; i < N; ++i) {
    cout << NGF[i] << " ";
  }

  cout << "\n";

  return 0;
}