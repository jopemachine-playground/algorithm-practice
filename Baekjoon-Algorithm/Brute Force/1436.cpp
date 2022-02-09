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

int hasSixMoreThan3(int num) {
  int cnt = 0;

  do {
    if (num % 10 == 6) {
      ++cnt;
    } else {
      cnt = 0;
    }

    if (cnt >= 3) return true;
  } while (num /= 10);

  return false;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> res(10001);
  int num = 665;

  for (int i = 1; i <= 10000; ++i) {
    while (!hasSixMoreThan3(num)) {
      ++num;
    }
    res[i] = num++;
  }

  cout << res[N] << "\n";
  return 0;
}