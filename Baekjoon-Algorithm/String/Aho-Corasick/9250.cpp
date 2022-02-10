// 백준 알고리즘 강의 중급
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

struct Node {
  int children[26];
  // 불일치 했을 때 다음 노드가 무엇인지 나타내는, fail 함수
  int pi;
  bool valid;
  Node () {
    for (int i = 0; i < 26; ++i) {
      children[i] = -1;
    }
    valid = false;
    pi = -1;
  }
};

vector<Node> trie;

int addNode() {
  Node node;
  trie.push_back(node);
  return (int) trie.size() - 1;
}

void add(int node, string& str, int index) {
  if (index == str.size()) {
    trie[node].valid = true;
    return;
  }
  int charIdx = str[index] - 'a';
  if (trie[node].children[charIdx] == -1) {
    int next = addNode();
    trie[node].children[charIdx] = next;
  }
  add(trie[node].children[charIdx], str, index + 1);
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;

  // 일단 pi를 갖는 트라이를 만들고 초기화, 문자열 추가.
  int trieRoot = addNode();
  vector<string> strs(N);

  for (int i = 0; i < N; ++i) {
    cin >> strs[i];
    addNode(trieRoot, strs[i], 0);
  }

  // BFS로 트라이를 돌면서 pi 값을 넣어주자.
  // 
  queue<int> que;
  trie[trieRoot].pi = trieRoot;
  que.push(trieRoot);

  while (!que.empty()) {
    int cur = que.front();
    que.pop();
    for (int i = 0; i < 26; ++i) {
      int next = trie[cur].children[i];
      if (next == -1) continue;

      // 길이가 1인 prefix
      if (cur == trieRoot) {
        trie[next].pi = trieRoot;
      } else {
        int x = trie[cur].pi;
        // KMP와 같은 로직
        while (x != trieRoot && trie[x].children[i] == -1) {
          x = trie[x].pi;
        }
        if (trie[x].children[i] != -1) {
          x = trie[x].children[i];
        }
        trie[next].pi = x;
      }
      int pi = trie[next].pi;
      trie[next].valid |= trie[pi].valid;
      que.push(next);
    }
  }

  // KMP로 문자열들을 검색해주자.

  int M;
  cin >> M;

  while (M--) {
    string s;
    cin >> s;

    int node = trieRoot;
    bool ok = false;
    for (int i = 0; i < s.size(); ++i) {
      int ch = s[i] - 'a';
      while (node != trieRoot && trie[node].children[ch] == -1) {
        node = trie[node].pi;
      }
      if (trie[node].children[ch] != -1) {
        node = trie[node].children[ch];
      }
      if (trie[node].valid) {
        ok = true;
      }
    }

    cout << (ok ? "YES" : "NO") << "\n";
  }

  return 0;
}