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

const long long mod = 1000000007LL;

long long dp[5001][5001];

// 길이가 N이고, 안 맞는 여는 괄호의 갯수가 L인 올바른 괄호 문자열의 갯수
long long getCnt(int n, int l) {
  long long& ans = dp[n][l];
  if (ans >= 0) return ans;

  // Base case
  if (n == 0 && l == 0) return 1;
  if (n == 0) return 0;

  long long res = 0;

  if (l + 1 <= n) {
    res += getCnt(n - 1, l + 1);
  }
  // 안 맞는 여는 괄호의 수가 음수 = 닫는 괄호가 더 많음 => 절대 올바른 괄호 문자열이 될 수 없다.
  if (l - 1 >= 0) {
    res += getCnt (n - 1, l - 1);
  }

  res %= mod;

  ans = res;

  return ans;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  // 보통 T에 따라 매 테스트 케이스에서 dp를 초기화 해줘야 하지만,
  // 이런 문제의 경우 이전 테스트 케이스에서 사용했던 값을 그대로 다음 테스트 케이스에 사용할 수 있다.
  // 즉, dp를 그대로 사용할 수 있다.
  // 테스트 케이스가 100까지이기 때문에, O(N)인 memset을 while문 내부로 넣으면 시간초과 나므로 주의.
  memset(dp, -1, sizeof(dp));
  while(T--) {
    int L;
    cin >> L;
    cout << getCnt(L, 0) << "\n";
  }

  return 0;
}