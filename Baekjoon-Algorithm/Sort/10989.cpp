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

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> cnts(10001, 0);

  while (N--) {
    int num;
    cin >> num;
    ++cnts[num];
  }

  for (int i = 0; i < 10001; ++i) {
    while (cnts[i]--) {
      cout << i << "\n";
    }
  }

  return 0;
}