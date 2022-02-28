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
#define endl '\n'

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

#define ll long long

struct TrieNode {
  int childs[10];
  bool valid;

  TrieNode () {
    for (int i = 0; i < 10; ++i) {
      childs[i] = -1;
    }
    valid = false;
  }
};

int init(vector<TrieNode>& trie) {
  TrieNode x;
  trie.push_back(x);
  return (int) trie.size() - 1;
}

void addNode(vector<TrieNode>& trie, int root, string& str, int idx) {
  if (idx >= str.length()) {
    trie[root].valid = true;
    return;
  }

  char ch = str[idx];

  if (trie[root].childs[ch - '0'] == -1) {
    int next = init(trie);
    trie[root].childs[ch - '0'] = next;
  }

  addNode(trie, trie[root].childs[ch - '0'], str, idx + 1);
}

bool check(vector<TrieNode>& trie, int root) {
  for (int i = 0; i < 10; ++i) {
    if (trie[root].childs[i] != -1) {
      if (trie[root].valid) {
        return false;
      }
      if (!check(trie, trie[root].childs[i])) {
        return false;
      }
    }
  }

  return true;
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    vector<TrieNode> trie;
    int root = init(trie);

    for (int i = 0; i < N; ++i) {
      string str;
      cin >> str;
      addNode(trie, root, str, 0);
    }

    if (check(trie, root)) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }

  return 0;
}