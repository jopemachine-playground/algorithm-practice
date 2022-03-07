/*
==============================+===============================================================
@ Title : 소수의 배수
@ Desc :
@ Ref :
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

int N; ll M;
int primes[10];

// num: 공배수.
ll go (int idx, ll num) {
  if (idx >= N) return 0;
  if (num * primes[idx] > M) return 0;
  ll ans = 0;
  // 공약수 갯수를 모두 세서 ans에 더해준다. 
  ans += (M / (num * primes[idx]));

  // 인덱스를 포함 안 하면 num을 그대로 두고 부호도 그대로 둔다.
  ans += go(idx + 1, num);
  // 인덱스를 포함 한다면 공배수에 prime 값을 곱해준다.
  ans -= go(idx + 1, num * primes[idx]);

  return ans;
}

int solve() {
  _FASTIOS;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> primes[i];
  }

  cout << go (0, 1) << '\n';
  return 0;
}