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

#define debug if constexpr (LOCAL) cout
#define _FASTIOS cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(0)
#define endl '\n'
#define ll long long
#define pii pair<int, int>

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

vector<int> tree[100001];

int answers[100001];
bool visited[100001];

void dfs(int root) {
  for (auto it = tree[root].begin(); it != tree[root].end(); ++it) {
    int childIdx = (*it);

    if (!visited[childIdx]) {
      answers[childIdx] = root;

      visited[childIdx] = true;
      dfs(childIdx);
      visited[childIdx] = false;
    }
  }
}

int solve() {
  _FASTIOS;
  int N;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    int t1, t2;
    cin >> t1 >> t2;
    tree[t1].push_back(t2);
    tree[t2].push_back(t1);
  }

  dfs(1);

  for (int i = 2; i <= N; ++i) {
    cout << answers[i] << '\n';
  }

  return 0;
}