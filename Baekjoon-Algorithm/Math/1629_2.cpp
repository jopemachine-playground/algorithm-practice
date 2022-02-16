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

using namespace std;

long long pow(long long A, long long B, long long C) {
  long long res = 1LL;
  while (B > 0) {
    if (B % 2 == 1) {
      res *= A;
      res %= C;
    }
    B >>= 1;
    A *= A;
    A %= C;
  }
  return res;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int A, B, C;
  cin >> A >> B >> C;

  cout << pow (A, B, C) << "\n";

  return 0;
}