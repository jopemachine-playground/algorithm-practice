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

using namespace std;

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> nums(N);
  int sum = 0;

  map<int, int> cntMap;

  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
    sum += nums[i];

    cntMap[nums[i]] = cntMap[nums[i]] + 1;
  }

  vector<pair<int, int>> cntMapValues(cntMap.begin(), cntMap.end());

  sort(cntMapValues.begin(), cntMapValues.end(), [](auto& u, auto& v) {
    return u.second > v.second;
  });

  sort(nums.begin(), nums.end());

  cout << round((double) sum / N) << "\n";

  cout << nums[N / 2] << "\n";

  if (
    cntMapValues.size() > 1 &&
    cntMapValues[0].second == cntMapValues[1].second
  ) {
    cout << cntMapValues[1].first << "\n";
  } else {
    cout << cntMapValues[0].first << "\n";
  }

  cout << nums[nums.size() - 1] - nums[0] << "\n";

  return 0;
}