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

  int N;
  cin >> N;

  int res = -1;

  int prev = 0;
  int next = 1;

  for (int i = 1; i < N; ++i) {
    int nextTemp = prev + next;
    prev = next;
    next = nextTemp;
  }
  res = next;

  cout << res << "\n";
  return 0;
}