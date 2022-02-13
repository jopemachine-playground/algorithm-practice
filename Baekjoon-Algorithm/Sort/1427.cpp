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

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  string N;
  cin >> N;
  
  vector<int> chars;
  for (int i = 0; i < N.length(); ++i) {
    chars.push_back(N.at(i) - '0');
  }

  sort(chars.rbegin(), chars.rend());

  for (int i = 0; i < N.length(); ++i) {
    cout << chars[i];
  }

  cout << "\n";

  return 0;
}