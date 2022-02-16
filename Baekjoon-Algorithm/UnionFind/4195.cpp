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

int find(vector<int>& parents, int u) {
  if (u == parents[u]) return u;
  return parents[u] = find(parents, parents[u]);
}

void merge(vector<int>& parents, vector<int>& sizes, int u, int v) {
  u = find(parents, u);
  v = find(parents, v);

  if (u != v) {
    // 더 높은 size를 가지는 집합을 루트로 만들자.
    // (더 낮은 랭크를 아래로 내리기 위해 ranks를 썼던 때와 마찬가지)
    if (sizes[u] < sizes[v]) swap(u, v);
    sizes[u] += sizes[v];
    parents[v] = u;
  }
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  while (N--) {
    int F;
    cin >> F;
    map<string, int> personMap;
    // 관계의 수가 최대 10만개 => 노드의 수는 최대 20만 개.
    vector<int> parents(200001);
    vector<int> sizes(200001);

    for (int i = 0; i <= 200001; ++i) {
      parents[i] = i;
      sizes[i] = 1;
    }

    int idx = 0;

    while (F--) {
      string A, B;
      cin >> A >> B;
      if (personMap.count(A) == 0) {
        personMap[A] = idx++;
      }
      if (personMap.count(B) == 0) {
        personMap[B] = idx++;
      }

      int root1 = find(parents, personMap[A]);
      int root2 = find(parents, personMap[B]);

      if (root1 != root2) {
        merge(parents, sizes, root1, root2);
      }

      cout << max(sizes[root1], sizes[root2]) << "\n";
    }
  }

  return 0;
}