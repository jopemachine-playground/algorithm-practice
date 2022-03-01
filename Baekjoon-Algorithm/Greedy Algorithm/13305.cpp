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

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<ll> roads(N - 1), points(N);

  for (int i = 0; i < N - 1; ++i) {
    cin >> roads[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> points[i];
  }

  ll res = 0;
  ll cost = 0;
  for (int i = 0; i < N; ++i) {
    ll curr = points[i];
    int j = i + 1;
    for (; j < N; ++j) {
      // 현재보다 더 싼 주유소를 발견했다면
      if (points[j] < curr) {
        cost += curr * roads[j - 1];
        res += cost;
        cost = 0;
        break;
      } 
      // 현재가 더 싸다면 지금 도로는 모두 현재 주유소의 가격으로 계산.
      else {
        cost += curr * roads[j - 1];
      }
    }
    i = j - 1;
  }

  if (cost != 0) res += cost;

  cout << res << "\n";

  return 0;
}