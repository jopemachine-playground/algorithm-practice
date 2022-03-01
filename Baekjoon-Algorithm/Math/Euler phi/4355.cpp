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

// 백준 알고리즘 중급
ll phi (ll N) {
  ll ans = N;
  for (ll i = 2; i * i <= N; ++i) {
    if (N % i == 0) {
      while (N % i == 0) {
        N /= i;
      }
      // 1 - 1/p의 곱 계산할 때 굳이 복잡하게 계산하지 말고
      // 아래처럼 뺄셈 한 번으로 계산 가능함;;
      // 처음에 이 부분이 잘 이해가 안 됬다..
      ans -= ans / i;
    }
  }

  if (N > 1) {
    ans -= ans / N;
  }
  return ans;
}

// int main() {
int solve() {
  _FASTIOS;
  int N;
  while (true) {
    cin >> N;
    if (N == 0) break;
    cout << phi(N) << "\n";
  }

  return 0;
}