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

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  ll M;

  cin >> N >> M;

  vector<int> primes(N);
  for (int i = 0; i < N; ++i) {
    cin >> primes[i];
  }

  ll res = 0;

  // 소수들로 가능한 모든 소수의 배수들을 만들어주자.
  // i에서 0을 제외해야 한다는 점 주의
  for (int i = 1; i < (1 << N); ++i) {
    int cnt = 0;
    ll comp = 1;
    // 가능한 소수의 배수를 만들고 그 배수를 만드는데 몇 개의 소수를 썼는지를 cnt에 기록.
    for (int j = 0; j < N; ++j) {
      if (i & (1 << j)) {
        comp *= primes[j];
        ++cnt;
        if (comp > M) {
          cnt = -1;
          break;
        }
      }
    }

    // 계산한 prime이 M보다 큰 경우는 제외해야 한다는 점 주의.
    if (cnt == -1) continue;

    // 예: 2 * 3의 배수의 경우 빼주자
    if (cnt % 2 == 0) {
      res -= (M / comp);
    } 
    // 예: 2의 배수, 2 * 3 * 5의 배수의 경우 더해주자
    else {
      res += (M / comp);
    }
  }

  cout << res << "\n";

  return 0;
}