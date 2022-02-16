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
  if (B == 0) {
    return 1LL;
  }
  if (B == 1) {
    return A % C;
  }

  if (B % 2 == 0) {
    long long temp = pow(A, B / 2, C);
    return (temp * temp) % C;
  }
  if (B % 2 == 1) {
    return (pow(A, 1, C) * pow(A, B - 1, C)) % C;
  }
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