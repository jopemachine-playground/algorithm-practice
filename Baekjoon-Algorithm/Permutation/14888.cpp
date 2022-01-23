// 백준 알고리즘 강의 중급
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int calc(vector<int>& nums, vector<int>& oprs) {
  int res = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    if (oprs[i - 1] == 0) {
      res += nums[i];
    }
    else if (oprs[i - 1] == 1) {
      res -= nums[i];
    }
    else if (oprs[i - 1] == 2) {
      res *= nums[i];
    }
    else {
      res /= nums[i];
    }
  }
  return res;
}

int solve() {
  int N;
  cin >> N;
  vector<int> nums(N);
  for (auto& num : nums) {
    cin >> num;
  }

  vector<int> oprs;
  for (int opr = 0; opr < 4; ++opr) {
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; ++i) {
      oprs.push_back(opr);
    }
  }

  sort(oprs.begin(), oprs.end());

  int max = -1, min = 101;

  vector<int> result;
  do {
    int temp = calc(nums, oprs);
    result.push_back(temp);
  } while (next_permutation(oprs.begin(), oprs.end()));

  auto ans = minmax_element(result.begin(), result.end());

  cout << *ans.second << "\n";
  cout << *ans.first << "\n";

  return 0;
}