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

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;

  vector<long long> dp(N + 1, 0);

  // dp에 i번 만큼 연산을 할 때의 최대 문자열 길이를 저장한다.
  for (int i = 1; i <= N; ++i) {
    // i번 만큼 1번 연산 후, (Ctrl A) + (Ctrl C) 누르고, j번 만큼 (Ctrl + V)를 반복하는 경우
    dp[i] = dp[i - 1] + 1;
  
    // j번 만큼 Ctrl + V를 누름.
    // 언제가 Ctrl V를 가장 많이 누를 때 인가? => 하나가 1번 연산, Ctrl A, Ctrl C가 하나씩 나오고 나머지가 모두 
    // Ctrl V인 경우 => 즉, i - 3이 최댓값. 
    for (int j = 1; j <= N; ++j) {
      if (i - j - 2 >= 0) {
        dp[i] = max(dp[i], dp[i - j - 2] * (j + 1));
      }
    }
  }

  cout << dp[N] << "\n";

  return 0;
}