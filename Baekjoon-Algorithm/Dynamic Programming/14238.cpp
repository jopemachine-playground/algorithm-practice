// 백준 알고리즘 중급
#include <iostream>
#include <vector>
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

// A, B, C의 최대 출근 횟수
int cnts[3];

// cnts의 합
int N;

// A, B, C의 갯수, 이전 출근 직원과 그 이전 출근 직원.
// dp 테이블엔 사실 상 bool 값인 해당 상태 집합이 나올 수 있는지 여부를 저장할 건데,
// 초기화 되지 않은 상태 (-1) 까지 나타내야할 땐 그냥 int 쓰면 된다.
int dp[51][51][51][3][3];

int isPossible(int A, int B, int C, int p1, int p2) {
  int& ans = dp[A][B][C][p1][p2];
  if (A + B + C == N) return ans = 1;
  if (ans != -1) return ans;

  if (A + 1 <= cnts[0] && isPossible(A + 1, B, C, 0, p1) == 1) {
    return ans = 1;
  }
  if (B + 1 <= cnts[1] && p1 != 1 && isPossible(A, B + 1, C, 1, p1) == 1) {
    return ans = 1;
  }
  if (C + 1 <= cnts[2] && p1 != 2 && p2 != 2 && isPossible(A, B, C + 1, 2, p1) == 1) {
    return ans = 1;
  }

  return ans = 0;
}

// dp 테이블에 저장한 건 A, B, C 갯수와 p1, p2에 따른 출근 가능 여부일 뿐이므로
// 직접 최적해를 찾는 함수를 따로 만들어야 함.
// dp 테이블을 만들고 돌려야된다.
string back(int A, int B, int C, int p1, int p2) {
  if (A + B + C == N) return "";

  if (A + 1 <= cnts[0] && isPossible(A + 1, B, C, 0, p1) == 1) {
    return "A" + back(A + 1, B, C, 0, p1);
  }
  if (B + 1 <= cnts[1] && p1 != 1 && isPossible(A, B + 1, C, 1, p1) == 1) {
    return "B" + back(A, B + 1, C, 1, p1);
  }
  if (C + 1 <= cnts[2] && p1 != 2 && p2 != 2 && isPossible(A, B, C + 1, 2, p1) == 1) {
    return "C" + back(A, B, C + 1, 2, p1);
  }

  return "";
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string str;
  cin >> str;

  N = str.length();

  // 순열을 다 만들려고 생각하면 n! 절대 안 된다..
  // => 그럼 필요한 건 문자열이 아니라 문자의 갯수.
  for (int i = 0; i < N; ++i) {
    ++cnts[str[i] - 'A'];
  }

  memset(dp, -1, sizeof(dp));

  // 시작할 때의 p1,p2는 A여도 상관 없기 때문에 (A는 따로 제약조건이 없으므로) A로 넣어준다.
  if (isPossible(0, 0, 0, 0, 0) == 0) {
    cout << -1 << "\n";
  } else {
    cout << back(0, 0, 0, 0, 0) << "\n";
  }

  return 0;
}