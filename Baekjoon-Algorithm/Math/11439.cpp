/*
==============================+===============================================================
@ Title : 이항 계수 5
@ Desc : 
  1. nCk를 에라토스테네스의 체를 이용한 소인수분해로, 해당 소수가 약수로 몇 개 포함되는지를 구할 수 있다.
  그것들을 모두 곱해주면 원하는 nCk가 나온다.
  2. 1676번과 같은 아이디어를 사용한다. (N!에 p가 몇 번 포함되는가?)
@ Ref : 백준 알고리즘 중급
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

ll N, M, mod;

// num!에 몇 개의 p가 포함되어 있는지 구한다.
ll cnt (ll num, ll p) {
  ll k = 0;

  while (num > 0) {
    k += num / p;
    num /= p;
  }

  return k;
}

// 원하는 mod 값으로 나머지 연산 해 주기 위해 pow 함수를 직접 만들어야함.
// 그리고, pow는 O(lg B)으로 구현해야 한다는 점 유의하자. (백준 1629번 문제 참고)
ll pow(ll A, ll B) {
  ll x = 1, y = A;

  while (B > 0) {
    if (B % 2 == 1) {
      x *= y;
      x % mod;
    }

    y *= y;
    y %= mod;

    B >>= 1;
  }

  return x;
}

int solve() {
  _FASTIOS;
  cin >> N >> M >> mod;
  ll ans = 1;
  vector<bool> isPrime(N + 1, true);

  // 에라토스테네스의 체로 N 이하의 소수를 모두 구하고 진행할 수도 있지만..
  // 아래처럼 반복문 한 번에서 처리해버릴 수 있다!
  for (ll i = 2; i <= N; ++i) {
    if (isPrime[i]) {
      for (ll j = i * i; j <= N; j += i) {
        isPrime[j] = false;
      }
      ll k = cnt(N, i) - cnt(M, i) - cnt(N - M, i);
      ans *= pow(i, k);
      ans %= mod;
    }
  }

  cout << ans << "\n";

  return 0;
}