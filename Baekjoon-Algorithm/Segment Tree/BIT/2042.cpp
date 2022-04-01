/*
==============================+===============================================================
@ Title : 구간 합 구하기
@ Desc :
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

// BIT에서 rightmost 1을 인덱스로 구간합을 계산.
ll sum(vector<ll>& tree, int i) {
  ll ans = 0;
  while (i > 0) {
    ans += tree[i];
    // Rightmost 1을 제거.
    i -= (i & -i);
  }
  return ans;
}

void update(vector<ll>& tree, int i, ll diff) {
  while (i < tree.size()) {
    tree[i] += diff;
    // Rightmost 1을 더해주면 부모 노드로 이동
    // 부모가 없을 때 (tree.size()보다 i가 클 때) 까지 이동하면
    // 트리의 모든 diff 업데이트가 마쳐진다.
    i += (i & -i);
  }
}

int solve() {
  _FASTIOS;
  int N, M, K;
  cin >> N >> M >> K;

  vector<ll> nums(N + 1);
  vector<ll> tree(N + 1);

  for (int i = 1; i <= N; ++i) {
    cin >> nums[i];
    update(tree, i, nums[i]);
  }

  int loopCnt = M + K;

  while (loopCnt--) {
    int a, b; ll c;
    cin >> a >> b >> c;
    if (a == 1) {
      // 전파할 변경사항:
      // b번째 수를 c로 바꾸라는 것.
      // 즉, diff 값은 c - nums[b].
      ll diff = c - nums[b];
      nums[b] = c;
      update(tree, b, diff);
    } else {
      cout << sum(tree, c) - sum(tree, b - 1) << '\n';
    }
  }

  return 0;
}