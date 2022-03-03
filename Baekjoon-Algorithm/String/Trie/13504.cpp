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

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

#define ll long long

struct Node {
  bool valid;
  int childs[2];
  Node () {
    childs[0] = -1;
    childs[1] = -1;
    valid = false;
  }
};

int init(vector<Node>& trie) {
  Node node;
  trie.push_back(node);
  return (int) trie.size() - 1;
}

void add(vector<Node>& trie, int root, int num, int idx) {
  if (idx <= -1) {
    trie[root].valid = true;
    return;
  }

  int childIdx = 1 & (num >> idx);
  if (trie[root].childs[childIdx] == -1) {
    int next = init(trie);
    trie[root].childs[childIdx] = next;
  }

  add(trie, trie[root].childs[childIdx], num, idx - 1);
}

int query(vector<Node>& trie, int root, int num, int idx) {
  if (idx <= -1) return 0;

  // num의 idx 번째 비트가 0인 경우, 1로 만든다.
  int childIdx = (1 & (num >> idx)) ^ 1;

  // 트라이에서 찾으려는 비트가 없다면 어쩔 수 없이 같은 비트로 둔다.
  // 트라이에서 찾으려는 비트의 반전 비트가 있는 경우, 반전 비트를 nextRoot로 한다.
  if (trie[root].childs[childIdx] == -1) {
    childIdx = 1 - childIdx;
  }

  assert(trie[root].childs[childIdx] != -1);
  if (trie[root].childs[childIdx] == -1) return 0;

  int bit = (childIdx == 1) ? (1 << idx) : 0;

  return bit | query(trie, trie[root].childs[childIdx], num, idx - 1);
}

int solve() {
  _FASTIOS;
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
      cin >> nums[i];
    }

    vector<Node> trie;
    int root = init(trie);

    int ans = 0;
    int xorAccum = 0;

    // 연속된 부분 수열의 두 인덱스 (begin, end)가 같은 경우 (간단히 말해 안 뽑는 경우)
    // xor 값의 합은 0이 된다.
    // 즉, 트라이엔 항상 0이 들어가야 한다.
    // 그런데, xorAccum은 0이 되지 않을 수 있기 때문에 트라이에 미리 0을 넣어준다.
    add(trie, root, xorAccum, 31);

    for (int i = 0; i < N; ++i) {
      xorAccum ^= nums[i];
      add(trie, root, xorAccum, 31);
      ans = max(ans, xorAccum ^ query(trie, root, xorAccum, 31));
    }
    
    cout << ans << "\n";
  }
  return 0;
}