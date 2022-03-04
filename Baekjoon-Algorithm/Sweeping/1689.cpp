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
  // 2*N 배열을 만들고, N개는 시작점, N개는 끝점으로 저장하자
  vector<pii> intervals(2 * N);
  for (int i = 0; i < N; ++i) {
    int s, e;
    cin >> s >> e;
    // 두 번째 값에 1과 -1을 넣어놓은 걸 유심히 보자.
    // s와 e 값이 같을 때 -1, 1 순으로 정렬되기 때문에
    // 끝나는 선분을 먼저 처리하기 때문에 선분이 끝나는 점에서 겹치면 세지 않는다.
    // 반면 1, -1로 넣어주면 시작하는 선분을 먼저 세서 선분이 끝나는 점에서 겹치는 선분도 세어준다.
    // (이렇게 할 경우 아래 반복문도 변경해야함)
    intervals[i] = {s, 1};
    intervals[i + N] = {e, -1};
  }

  // 시작점, 끝점 가리지 않고 정렬.
  sort(intervals.begin(), intervals.end());

  int ans = 0;
  int cnt = 0;
  for (auto& p : intervals) {
    // 시작점이라면 선분의 개수가 1 증가,
    // 끝점이라면 선분의 개수가 1 감소한다.
    cnt += p.second;
    if (cnt > ans) ans = cnt;
  } 
  cout << ans << "\n";

  return 0;
}