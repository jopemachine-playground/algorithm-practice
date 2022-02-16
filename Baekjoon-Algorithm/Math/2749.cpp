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

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  long long N;
  cin >> N;

  // 다른 코드로 먼저 주기를 찾아둬도 되고 사실 그냥 위에 주기 찾는 코드를 넣어줘도 된다.
  // Ref: https://www.acmicpc.net/problem/9471
  int T = 1500000;

  long long prev = 0;
  long long next = 1;

  for (int i = 2; i <= N % T; ++i) {
    long long nextTemp = (prev + next) % 1000000;
    prev = next;
    next = nextTemp;
  }

  cout << next << "\n";

  return 0;
}