/*
==============================+===============================================================
@ Title : 거듭제곱
@ Desc : 
  각각의 수들을 포함할 지 안 할지를 이진법으로 나타낼 수 있음.
  그리고 각각의 해당하는 비트들을 3의 거듭제곱 꼴로, (즉 3진법으로) 나타낼 수 있음.
  결론적으로 N을 2진법으로 나타낸 후 3진법으로 읽으면, N번째로 작은 3의 제곱수의 합이 된다.
  거듭 제곱이라기 보단 진법 관련된 문제인 듯.
@ Ref : https://donggod.tistory.com/47
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

int solve() {
  _FASTIOS;
  ll N;
  cin >> N;

  queue<int> que;
  while (N > 0) {
    que.push(N % 2);
    N >>= 1;
  }

  ll ans = 0;
  ll k = 1;
  while (que.size() > 0) {
    ans += k * que.front();
    k *= 3;
    que.pop();
  }

  cout << ans << '\n';

  return 0;
} 