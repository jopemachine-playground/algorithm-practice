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

// int main() {
int solve() {
  _FASTIOS;
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;

    ll ans = 1;
    int r = 1;
    // Ref: https://luv-n-interest.tistory.com/956
    // M! / (M - N)!을 i로 한 번에 순회할 수 있다.
    // 30!은 너무 큰 수라 ll에 못 담음. 한 번에 계산 안 하고 나눗셈과 같이 진행하면
    // 오버플로우를 피할 수 있다.
    for (int i = M; i > M - N; --i) {
      ans *= i;
      ans /= r++;
    }

    cout << ans << "\n";
  }

  return 0;
}