/*
==============================+===============================================================
@ Title : 오아시스 재결합
@ Desc : 히스토그램 문제와 다를 게 없어보였지만, 키가 같은 사람이 들어왔을 때를 
따로 처리해줘야 하는 부분을 생각하지 못했다.
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

int solve() {
  _FASTIOS;
  int N;
  cin >> N;

  // 높이, (연속되는) 해당 높이에 해당하는 인원 수
  stack<pii> heights;
  ll ans = 0;
  int h, topHeight, cnt;

  // 라인 스위핑
  for (int i = 0; i < N; ++i) {
    cin >> h;
    pii pair = {h, 1};

    // i명 사람과 매칭될 수 있는 사람 수를 다 더해줌
    // 키가 같은 경우에도 서로 볼 수 있음에 주의하자.
    // 이걸 처리해주기 위해서 stack에 int가 아니라 pii 형태로 갯수를 함께 저장해서 더해줘야 된다!
    while (!heights.empty() && heights.top().first <= h) {
      tie(topHeight, cnt) = heights.top();

      ans += (ll) cnt;

      if (topHeight == h) {
        pair.second += cnt;
      }

      heights.pop();
    }

    // 스택이 비어 있지 않으면 서로 볼 수 있다.
    // => 1 더해줘야 함.
    if (!heights.empty()) ++ans;

    heights.push(pair);
  }

  cout << ans << '\n';

  return 0;
}