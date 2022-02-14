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

  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
  }

  vector<int> original(nums.begin(), nums.end());

  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());

  for (int i = 0; i < N; ++i) {
    // 아래처럼 lower_bound 같은 iterator 반환하는 함수들에 대해 아래처럼 nums의 시작 위치를 빼 줌으로써
    // 해당 위치 (인덱스)를 구할 수 있단 걸 알아두자.
    cout << lower_bound(nums.begin(), nums.end(), original[i]) - nums.begin() << " ";
  }

  cout << "\n";
  
  return 0;
}