// 백준 알고리즘 중급
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

int N, K;

struct Node {
  bool valid;
  int childs[2];
  int cnts[2];

  Node() {
    valid = false;
    childs[0] = -1;
    childs[1] = -1;

    cnts[0] = 0;
    cnts[1] = 0;
  }
};

int init(vector<Node>& trie) {
  Node root;
  trie.push_back(root);
  return (int) trie.size() - 1;
}

void add(vector<Node>& trie, int root, int num, int bit) {
  if (bit <= -1) {
    trie[root].valid = true;
    return;
  }

  int childIdx = 1 & (num >> bit);
  if (trie[root].childs[childIdx] == -1) {
    int next = init(trie);
    trie[root].childs[childIdx] = next;
  }

  ++trie[root].cnts[childIdx];

  add(trie, trie[root].childs[childIdx], num, bit - 1);
}

int query(vector<Node>& trie, int root, int num, int bit) {
  if (bit == -1) return 0;

  int ans = 0;

  int c1 = 1 & (num >> bit);
  int c2 = 1 & (K >> bit);

  if (c2 == 1) {
    ans += trie[root].cnts[c1];
    c1 = 1 - c1;
  }

  if (trie[root].childs[c1] == -1) {
    return ans;
  }

  ans += query(trie, trie[root].childs[c1], num, bit - 1);

  return ans;
}

int solve() {
  _FASTIOS;
  cin >> N >> K;
  vector<Node> trie;
  int root = init(trie);

  ll ans = 0;
  int xorPrefix = 0;
  add(trie, root, xorPrefix, 31);

  for (int i = 0; i < N; ++i) {
    int num;
    cin >> num;
    xorPrefix ^= num;
    ans += query(trie, root, xorPrefix, 31);
    add(trie, root, xorPrefix, 31);
  }

  cout << ans << "\n";

  return 0;
}