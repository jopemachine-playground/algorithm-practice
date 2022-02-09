// 백준 알고리즘 강의 중급
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

using namespace std;

// mod와 base 값은 경험과 운으로 넣어야 한다;;
long long mod = 2147483647;
int base = 256;

long long getHash (string s) {
  long long ans = 0;
  for (char ch : s) {
    // 진법 계산 관련:: 예를 들어,
    // a * base ^ 2 + b * base + c
    // => ((a * base) + b) * base + c
    // 로 계산 가능하기 때문에 아래처럼 쓸 수 있다.
    ans = (ans * base + ch) % mod;
  }
  return ans;
}

bool match (string s, string p) {
  int n = s.length();
  int m = p.length();
  // s의 길이가 m보다 짧은 경우 일치할 수 없음
  if (n < m) return false;
  long long hash_p = getHash(p);
  long long hash_s = getHash(s.substr(0, m));

  // 어차피 p의 길이는 일정하니까 맨 앞 자릿 수를 구해놓자.
  long long first = 1;
  for (int i = 0; i < m - 1; ++i) {
    first = (first * base) % mod;
  }

  for (int i = 0; i <= n - m; ++i) {
    if (hash_p == hash_s) {
      if (s.substr(i, m) == p) return true;
    }
    // 여기가 중요.
    // 매번 hash(s)를 계산하면 O(M)인데 그럴 필요 없다.
    // 어차피 부분문자열 검색에서 슬라이딩 윈도우로 땡기고 앞과 뒤만 바꿔주면 되는 상황이니까
    // 앞 자리 하나 빼 주고 앞으로 한 번 떙기고 뒷 자리 넣으면 다음 hash(s) 값이 O(1)에 나온다.
    if (i + m < n) {
      // 앞 자리 하나 빼 주고,
      hash_s = hash_s - (s[i] * first) % mod;
      // 음수가 나왔을 수 있기 때문에 mod를 한 번 더해주고 mod로 나눠주자.
      hash_s = (hash_s + mod) % mod;
      // hash_s엔 한 자리 앞으로 땡기고, i+m 번째 아스키 코드 값 더해주자.
      hash_s = ((hash_s * base) % mod) + s[i + m] % mod;
    }
  }

  return false;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  string s, p;
  cin >> s >> p;
  cout << (match(s, p) ? 1 : 0) << "\n";

  return 0;
}