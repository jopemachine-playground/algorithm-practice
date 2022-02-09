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

struct Trie {
  struct Node {
    int childs[26];
    bool valid;

    Node () {
      for (int i = 0; i < 26; ++i) {
        childs[i] = -1;
      }
      valid = false;
    }
  };

  vector<Node> trie;
  int root;

  int addNode () {
    Node x;
    trie.push_back(x);
    return (int) trie.size() - 1;
  }

  Trie() {
    root = addNode();
  }

  void add (int node, string& str, int index) {
    if (index == str.length()) {
      trie[node].valid = true;
      return;
    }

    int charIdx = str[index] - 'a';

    if (trie[node].childs[charIdx] == -1) {
      int next = addNode();
      trie[node].childs[charIdx] = next;
    }

    int child = trie[node].childs[charIdx];

    add(child, str, index + 1);
  }

  void add(string& str) {
    add(root, str, 0);
  }

  bool search(int node, string& str, int index) {
    if (node == -1) return false;
    if (index == str.length()) return true;
    int charIdx = str[index] - 'a';
    int childNode = trie[node].childs[charIdx];
    return search(childNode, str, index + 1);
  }

  bool search(string& str) {
    return search(root, str, 0);
  }
};

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, M;

  Trie trie;

  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    trie.add(str);
  }

  int ans = 0;

  for (int i = 0; i < M; ++i) {
    string str;
    cin >> str;
    if (trie.search(str)) {
      ++ans;
    }
  }

  cout << ans << "\n";
  return 0;
}