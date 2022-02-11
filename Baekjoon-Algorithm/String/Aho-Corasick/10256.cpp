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

using namespace std;

struct Node {
  int childs[4];
  int pi;
  int cnt;
  Node () {
    for (int i = 0; i < 4; ++i) {
      childs[i] = -1;
    }
    cnt = 0;
    pi = -1;
  }
};

int toNode(char x) {
  if (x == 'A') return 0;
  if (x == 'T') return 1;
  if (x == 'G') return 2;
  if (x == 'C') return 3;
  return -1;
}

vector<Node> trie;

int addNode() {
  Node x;
  trie.push_back(x);
  return (int) trie.size() - 1;
}

void add(int node, string& s, int index) {
  if (index == s.size()) {
    trie[node].cnt = 1;
    return;
  }

  int c = toNode(s[index]);
  if (trie[node].childs[c] == -1) {
    int next = addNode();
    trie[node].childs[c] = next;
  }

  add(trie[node].childs[c], s, index + 1);
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;

  while (T--) {
    trie.clear();
    int N, M;
    cin >> N >> M;
    string dna, marker;
    cin >> dna >> marker;

    int trieRoot = addNode();
    vector<string> mutations;

    for (int i = 0; i < M; ++i) {
      for (int j = i + 1; j <= M; ++j) {
        string tmp = marker;
        reverse(tmp.begin() + i, tmp.begin() + j);
        mutations.push_back(tmp);
      }
    }

    // sort, erase, unique를 사용해 vector에서 중복된 값들을 모두 제거하는 코드를 잘 알아두자.
    // unique는 중복 원소가 있을 경우 이를 모두 뒤로 보내고 첫 중복원소의 인덱스를 리턴
    // 그럼 거기서 부터 원래 vector의 end 까지를 erase 해 주면 vector에 유일한 값들만 남게 된다.
    sort(mutations.begin(), mutations.end());
    mutations.erase(unique(mutations.begin(), mutations.end()), mutations.end());
    for (string& mutation: mutations) {
      add(trieRoot, mutation, 0);
    }

    queue<int> que;
    trie[trieRoot].pi = trieRoot;
    que.push(trieRoot);

    while (!que.empty()) {
      int cur = que.front();
      que.pop();

      for (int i = 0; i < 4; ++i) {
        int next = trie[cur].childs[i];
        if (next == -1) continue;
        // 길이 1
        if (cur == trieRoot) trie[next].pi = trieRoot;
        else {
          int x = trie[cur].pi;
          while (x != trieRoot && trie[x].childs[i] == -1) {
            x = trie[x].pi;
          }
          if (trie[x].childs[i] != -1) {
            x = trie[x].childs[i];
          }
          trie[next].pi = x;
        }
        int pi = trie[next].pi;
        trie[next].cnt += trie[pi].cnt;
        que.push(next);
      }
    }

    int ans = 0;
    int node = trieRoot;
    for (int i = 0; i < N; ++i) {
      int c = toNode(dna[i]);
      while (node != trieRoot && trie[node].childs[c] == -1) {
        node = trie[node].pi;
      }
      if (trie[node].childs[c] != -1) {
        node = trie[node].childs[c];
      }

      ans += trie[node].cnt;
    }

    cout << ans << "\n";
  }

  return 0;
}