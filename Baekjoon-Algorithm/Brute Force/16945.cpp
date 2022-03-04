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

bool isMagic(vector<int>& D) {
  int magicValue = D[0] + D[1] + D[2];
  for (int i = 0; i < 3; ++i) {
    int sum = 0;
    for (int j = 0; j < 3; ++j) {
      sum += D[i * 3 + j];
    }
    if (magicValue != sum) return false;
  }

  // 위 코드에서 그대로 j와 i의 순서만 바꿔주면
  // 행의 합을 구하는 코드가 열의 합을 구하는 코드가 된다!
  for (int j = 0; j < 3; ++j) {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
      sum += D[i * 3 + j];
    }
    if (magicValue != sum) return false;
  }

  if (D[0] + D[4] + D[8] != magicValue) return false;
  if (D[2] + D[4] + D[6] != magicValue) return false;
  return true;
}

int diff(vector<int>& A, vector<int>& D) {
  int ans = 0;
  for (int i = 0; i < A.size(); ++i) {
    ans += abs(A[i] - D[i]);
  }
  return ans;
}

int solve() {
  _FASTIOS;
  // 입력을 이차원 배열로 받으면 순열을 돌릴 수 없다.
  // 순열을 이용해 풀면 간단할 것 같으니 일차원 배열로 입력을 받자.
  vector<int> A(9);
  for (int i = 0; i < 9; ++i) {
    cin >> A[i];
  }

  vector<int> D(9);
  for (int i = 0; i < 9; ++i) {
    D[i] = i + 1;
  }

  int ans = 2e9;

  do {
    if (isMagic(D)) {
      ans = min(ans, diff(A, D));
    }
  } while (next_permutation(D.begin(), D.end()));

  cout << ans << "\n";

  return 0;
}