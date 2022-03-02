// Ref: https://j3sung.tistory.com/235
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

// 0의 개수를 N을 1씩 빼면서 세면 20억이라 시간초과 난다. (O(N))
// N!이 x를 몇 번이나 소인수로 갖는 지를 구하는 함수를 아래처럼 작성할 수 있다.
// 예를 들어 8! = 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 에서,
// (2의 거듭제곱 중) 2만을 소인수로 갖는 수들은 2로 나누면 4개, 4만 소인수로 갖는 8 / 4 = 2개,
// 8만 소인수로 갖는 수는 1개, 합쳐서 7개이니 2는 7번 등장한다.
ll countZero(ll N, ll x) {
  if (x == 0LL) return 0LL;

  ll cnt = 0LL;

  ll k = x;
  while (k <= N) {
    cnt += N / k;
    k *= x;
  }

  return cnt;
}

int solve() {
  _FASTIOS;
  int N, M;
  cin >> N >> M;

  // nCm 값의 2의 갯수와 5의 갯수만 세면 nCm은 계산 안 해도 된다. (값이 너무 커서 그냥은 계산 못 한다)
  // nCm 계산 공식에 따라 n!의 2, 5의 갯수에서 m!, (n-m)!의 2, 5의 갯수를 각각 빼 주면 된다.
  ll twoCnt = countZero(N, 2) - countZero(M, 2) - countZero(N - M, 2);
  ll fiveCnt = countZero(N, 5) - countZero(M, 5) - countZero(N - M, 5);

  cout << min(twoCnt, fiveCnt) << "\n";

  return 0;
}