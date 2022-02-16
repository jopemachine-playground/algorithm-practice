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

  int N, K;
  cin >> N >> K;
  
  int A = 1, B = 1, C = 1;

  for (int i = N; i >= 1; --i) {
    A *= i;
  }

  for (int i = K; i >= 1; --i) {
    B *= i;
  }

  for (int i = N - K; i >= 1; --i) {
    C *= i;
  }

  cout << (A / (B * C));

  return 0;
}