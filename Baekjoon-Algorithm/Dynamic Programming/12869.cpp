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

int dp[61][61][61];

// 어차피 세 마리 뿐이니 그냥 인자로 넣자..
int attack(int scv1, int scv2, int scv3) {
  // 배열 인자에 음수가 들어가면 예외 처리해 줘야 되고 뭐하고..
  // 복잡하게 풀지 말고 음수가 나올 때 마다 0으로 바꿔버리자!
  // 그럼 세 scv의 체력이 모두 음수가 될 때만 베이스 케이스로 처리해주면 된다.
  if (scv1 < 0) return attack(0, scv2, scv3);
  if (scv2 < 0) return attack(scv1, 0, scv3);
  if (scv3 < 0) return attack(scv1, scv2, 0);

  if (scv1 == 0 && scv2 == 0 && scv3 == 0) return 0;

  int& ans = dp[scv1][scv2][scv3];
  if (ans >= 0) return ans;

  vector<int> deltas = { 1, 3, 9 };

  ans = 2000000000;

  do {
    ans = min(ans, attack(scv1 - deltas[0], scv2 - deltas[1], scv3 - deltas[2]) + 1);
  } while (next_permutation(deltas.begin(), deltas.end()));

  return ans;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  // N이 세 마리까지인데 어차피 3차원 배열 dp를 쓸 것임..
  // => 그냥 세 마리라고 가정하고 1마리나 2마리가 들어오면 남은 마릿수는 애초에 체력이 0이었다고 가정하면 된다.
  vector<int> scvs(3, 0);

  memset(dp, -1, sizeof(dp));

  for (int i = 0; i < N; ++i) {
    cin >> scvs[i];
  }

  attack(scvs[0], scvs[1], scvs[2]);

  cout << dp[scvs[0]][scvs[1]][scvs[2]] << '\n';

  return 0;
}