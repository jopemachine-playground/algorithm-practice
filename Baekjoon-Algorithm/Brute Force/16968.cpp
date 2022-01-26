// 경우의 수를 계산해보는 게 아닌 실제로 모두 만들어보는 풀이. 
#include <algorithm>
#include <iostream>

using namespace std;

int go (string&s, int index, char last) {
  if (s.length() == index) {
    return 1;
  }
  char start = (s[index] == 'c' ? 'a' : '0');
  char end = (s[index] == 'c' ? 'z' : '9');

  int ans = 0;
  for (char i = start; i <= end; ++i) {
    // 같은 숫자, 알파벳은 이어질 수 없다.
    if (i != last) {
      ans += go(s, index + 1, i);
    }
  }
  return ans;
}

int solve() {
  string s;
  cin >> s;
  cout << go(s, 0, ' ') << "\n";
  return 0;
}