// 백준 알고리즘 중급
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
#define endl '\n'

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

#define ll long long

vector<int> getPossibleSums(const vector<int>& nums) {
  vector<int> sums;
  // O(N^2)으로 가능한 모든 수를 뽑아본다.
  // 가능한 모든 수로 가능한 Sum의 조합을 모두 구해본다.
  for (int i = 0; i < nums.size(); ++i) {
    int sum = 0;
    for (int j = i; j < nums.size(); ++j) {
      sum += nums[j];
      sums.push_back(sum);
    }
  }
  return sums;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  int N;
  cin >> N;
  vector<int> nums_1(N);
  for (int i = 0; i < N; ++i) {
    cin >> nums_1[i];
  }

  vector<int> sums_1 = getPossibleSums(nums_1);

  int M;
  cin >> M;
  vector<int> nums_2(M);
  for (int i = 0; i < M; ++i) {
    cin >> nums_2[i];
  }

  vector<int> sums_2 = getPossibleSums(nums_2);

  sort(sums_1.begin(), sums_1.end());
  sort(sums_2.begin(), sums_2.end());

  ll ans = 0;

  // 해당하는 A의 가능한 모든 부분합에 대해서 B의 모든 가능한 부분합, T - sum 값을 이분탐색으로 찾아보는 식으로 풀 수 있다.
  for (int i = 0; i < sums_1.size(); ++i) {
    // equal_range : 특정 값의 상한, 하한을 모두 찾아 std::pair로 리턴.
    auto p = equal_range(sums_2.begin(), sums_2.end(), T - sums_1[i]);
    // 상한 - 하한 = 갯수
    ans += p.second - p.first;
  }

  cout << ans << "\n";

  return 0;
}