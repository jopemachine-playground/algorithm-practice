/*
==============================+===============================================================
@ Title : 길의 개수
@ Desc : 그래프 모델링과 발상 모두 힘들어보이는 문제..
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

using matrix = vector<vector<ll>>;
const ll mod = 1000003LL;

matrix operator * (const matrix& u, const matrix& v) {
  assert(u.size() == v.size());

  int N = u.size();

  matrix ret (N, vector<ll>(N, 0));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        ret[i][j] += u[i][k] * v[k][j];
      }
      ret[i][j] %= mod;
    }
  }
  return ret;
}

int solve() {
  _FASTIOS;
  int N, S, E, T;
  cin >> N >> S >> E >> T;

  // 그래프의 연결성을 나타내는 그래프.
  // 정점들을 모두 5등분 해서 0분 후 ~ 4분 후 까지 나눠주자.
  // [i][j]가 i에서 j로 가는 방법의 수를 나타낸다.
  // 이렇게 이차원 배열로 나타내기 위해, 정점 변경될 때 마다 5씩 커지게 하고,
  // 이 값에 시간대를 더해서 인덱스를 나타낸다.
  matrix graph(N * 5, vector<ll>(N * 5));

  // 각 정점들은 다음 시간대와 연결되어 있어야 한다.
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 4; ++j) {
      int curr = 5 * i + j;
      int next = curr + 1;
      graph[curr][next] = 1; 
    }
  }

  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    assert(str.size() == N);

    for (int j = 0; j < N; ++j) {
      int v = (str[j] - '0');
      if (v != 0) {
        // i에서 j로 갈 때 걸리는 시간이 v이다
        // 즉, (i, v - 1) => (j, 0) 정점으로 이동한다.
        graph[5 * i + v - 1][5 * j] = 1;
      }
    }
  }

  matrix ans(N * 5, vector<ll>(N * 5));

  // 단위 행렬 만들기
  for (int i = 0; i < N * 5; ++i) {
    ans[i][i] = 1;
  }

  // 행렬의 거듭 제곱을 빠르게 구하기 위한 이진수의 원리.
  while (T > 0) {
    if (T & 1) {
      ans = ans * graph;
    }
    graph = graph * graph;
    T >>= 1;
  }

  S -= 1;
  E -= 1;

  cout << ans[5 * S][5 * E] << '\n';

  return 0;
}