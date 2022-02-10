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

int ln = 0, rn = 0;
// 찾는 문자열
string A, T;
// 찾으려는 반대 문자열
string reverseA;

vector<char> l(300001);
vector<char> r(300001);

// 지워진 경우 true 리턴.
bool removePossibleA(int type) {
  // type에 따라 다른 인자를 받는 식으로 함수를 구현해도 되지만,
  // 이런 식으로 전역변수 참조를 type에 따라 변경해 구현하는 방법도 있다.
  int len = type == 0 ? ln : rn;
  vector<char>& stk = type == 0 ? l : r;
  string& str = type == 0 ? reverseA : A;

  if (len < A.length()) {
    return false;
  }

  for (int i = 0; i < A.length(); ++i) {
    // 스택은 top에서 부터 봐야하기 때문에, len-i-1 부터 봐줘야 한다는 점에 주의.
    // (len - 1이 stk의 top 위치니까 여기서 부터 시작하는 것)
    if (stk[len - i - 1] != str[i]) {
      return false;
    }
  }

  // 실제로 줄일 필요 없음 그냥, ln, rn 값을 빼는 것으로 스택에서 지우는 걸로 처리.
  if (type == 0) {
    ln -= A.length();
  } else {
    rn -= A.length();
  }

  return true;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> A >> T;
  reverseA = A;

  reverse(reverseA.begin(), reverseA.end());

  int left = 0;
  int right = T.size() - 1;

  // type이 0일 땐 왼쪽 문자열 교체 작업을, 1일 땐 오른쪽 문자열 교체 작업을 해 주자.
  int type = 0;

  while (left <= right) {
    if (type == 0) {
      l[ln++] = T[left++];
    } else {
      r[rn++] = T[right--];
    }

    if (removePossibleA(type)) {
      type = 1 - type;
    }
  }

  // 반복문이 끝났으면 왼쪽 버퍼에 있는 값을 오른쪽 버퍼로 모두 옮기자.
  for (int i = ln - 1; i >= 0; --i) {
    r[rn++] = l[i];
    // type 1, 즉 오른쪽 버퍼에 있는 A를 매 반복문마다 모두 지워주자.
    removePossibleA(1);
  }

  // 그리고 오른쪽 버퍼를 반대로 출력하면 된다.
  for (int i = rn - 1; i >= 0; --i) {
    cout << r[i];
  }

  cout << "\n";

  return 0;
}