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
  set<string> strSet;
  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    strSet.insert(str);
  }

  vector<string> dict(strSet.begin(), strSet.end());
  stable_sort(dict.begin(), dict.end(), [](const auto& u, const auto& v) {
    return u.length() < v.length();
  });

  for (int i = 0; i < dict.size(); ++i) {
    cout << dict[i] << "\n";
  }
  return 0;
}