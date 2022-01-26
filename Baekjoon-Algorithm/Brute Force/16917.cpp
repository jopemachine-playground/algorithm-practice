#include <iostream>
#include <algorithm>

using namespace std;

int solve() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int ans = A * X + B * Y;
  for (int i = 0; i <= 100000; ++i) {
    int res = (2 * i * C) + (max(X - i, 0) * A) + (max(Y - i, 0) * B);
    if (ans > res) ans = res;
  }
  cout << ans << "\n";
  return 0;
}