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
    // 모든 알파벳에 대한 자식들을 저장. 자식이 없으면 -1.
    int childs[26];
    // 저장하고 있는 문자열이 맞음
    bool valid;

    // 노드를 만들면 모든 child를 -1로 valid를 false로 초기화.
    Node() {
      for (int i = 0; i < 26; ++i) {
        childs[i] = -1;
      }
      valid = false;
    }
  };

  vector<Node> trie;
  int root;

  int makeNewNode() {
    Node x;
    trie.push_back(x);
    return (int) trie.size() - 1;
  }

  Trie() {
    root = makeNewNode();
  }

  void add(int node, string& str, int index) {
    // Base case. 추가하려는 str을 다 돌았으면 valid하게 만들고 리턴.
    if (index == str.size()) {
      trie[node].valid = true;
      return;
    }

    // 이번 호출에서 추가할 character의 인덱스.
    int charIdx = str[index] - 'a';

    // 새 노드를 만들어 추가해 줄 건데, 이미 있으면 추가 안 하고 넘어감.
    if (trie[node].childs[charIdx] == -1) {
      int next = makeNewNode();
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
    // 트리 끝까지 내려온 경우, valid한 값인지 확인.
    if (index == str.length()) return trie[node].valid;
    int charIdx = str[index] - 'a';
    int child = trie[node].childs[charIdx];
    return search(child, str, index + 1);
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