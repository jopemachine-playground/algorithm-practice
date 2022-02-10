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

  stack<int> stk;
  vector<int> NGE(N);
  for (int i = N - 1; i >= 0; --i) {
    while (!stk.empty() && (nums[stk.top()] <= nums[i])) {
      stk.pop();
    }

    if (stk.empty()) {
      NGE[i] = -1;
    } else {
      NGE[i] = nums[stk.top()];
    }
    stk.push(i);
  }

  for (int i = 0; i < N; ++i) {
    cout << NGE[i] << " ";
  }

  cout << "\n";

  return 0;
}