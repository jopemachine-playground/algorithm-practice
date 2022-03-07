// Ref: https://jaimemin.tistory.com/1251
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

int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}

// int main() {
int solve() {
  _FASTIOS;
  int N;
  cin >> N;
  vector<int> nums(N);
  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
  }

  // 모든 가능한 i에 대해 v[i] - v[i - 1]은 m * k 꼴로 나타나야한다.
  // 즉, m의 가능한 집합은 v[i] - v[i - 1]의 최대 공약수의 공약수들이 된다.
  // v[i]가 항상 v[i - 1] 보다 크게 만들기 위해 (음수 제거) 오름차순으로 정렬.
  sort(nums.begin(), nums.end());

  int gcdVal = nums[1] - nums[0];
  for (int i = 2; i < N; ++i) {
    gcdVal = gcd(gcdVal, nums[i] - nums[i - 1]);
  }

  // 아래 반복문은 i가 1일 때 돌지 않기 때문에, gcd 값은 따로 push 해 줘야 한다.
  vector<int> res {gcdVal};

  // 모든 공약수들을 찾아주자.
  // m * k 꼴이므로 gcd 값 보다 작거나 같은 i * i에 대해 찾으면 된다.
  for (int i = 2; i * i <= gcdVal; ++i) {
    if (gcdVal % i == 0) {
      res.push_back(i);
      res.push_back(gcdVal / i);
    }
  }

  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());

  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << " ";
  }
  cout << "\n";

  return 0;
}