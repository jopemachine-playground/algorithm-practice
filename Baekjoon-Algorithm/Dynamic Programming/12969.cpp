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

char ans[32];

int N, K;
// 문자열의 길이, A의 갯수, B의 갯수, 가능한 쌍의 수.
// 최적화 문제가 아니라 결정 문제이기 때문에, 가능한 쌍의 수를 
// (int dp[31][31][31] 대신) 아래처럼 bool 배열을 선언해 풀자.
// 전역 변수 bool 배열의 경우 0으로 초기화 되므로 모두 false로 초기화 된다.
bool dp[31][31][31][436];

// 다른 dp 문제들에서 작성한 것들과 다르게 하나만 찾으면 바로 리턴해주면 된다는 것에 유의.
int go(int idx, int a, int b, int p) {
  if (idx == N) {
    return p == K;
  }

  // 계산해 본 적 있다면 무조건 불가능.
  if (dp[idx][a][b][p]) return false;
  dp[idx][a][b][p] = true;

  ans[idx] = 'A';
  if (go(idx + 1, a + 1, b, p)) return true;
  
  ans[idx] = 'B';
  if (go(idx + 1, a, b + 1, p + a)) return true;
  
  ans[idx] = 'C';
  if (go(idx + 1, a, b, p + a + b)) return true;

  return false;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> N >> K;

  if (go(0, 0, 0, 0)) {
    cout << ans << "\n";
  }
  else {
    cout << -1 << "\n";
  }

  return 0;
}