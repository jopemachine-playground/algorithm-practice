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

int find(vector<int>& parents, int x) {
  if (x == parents[x]) {
    return x;
  } else {
    return parents[x] = find(parents, parents[x]);
  }
}

void merge(vector<int>& parents, vector<int>& ranks, int x, int y) {
  x = find(parents, x);
  y = find(parents, y);
  if (x == y) return;
  // 랭크가 더 작은 트리가 항상 밑으로 들어가야 한다.
  // y가 더 랭크가 크다면 y가 더 작은 랭크를 갖도록 스왑해준다.
  if (ranks[x] < ranks[y]) swap(x, y);
  // 경로 압축
  parents[y] = x;
  // rank 
  if (ranks[x] == ranks[y]) {
    ranks[x] = ranks[y] + 1;
  }
}

// int main() {
int solve() {
  int N, M;
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  vector<int> nums(N + 1);
  vector<int> ranks(N + 1);

  for (int i = 0; i <= N; ++i) {
    nums[i] = i;
    ranks[i] = 0;
  }

  while (M-- > 0) {
    int type, a, b;
    cin >> type >> a >> b;

    if (type == 0) {
      merge(nums, ranks, a, b);
    } else if (type == 1) {
      if (find(nums, a) == find(nums, b)) {
        cout << "YES" << "\n";
      } else {
        cout << "NO" << "\n";
      }
    }
  }

  return 0;
}