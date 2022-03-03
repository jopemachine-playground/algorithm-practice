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
#define endl '\n'

#ifdef BOJ
constexpr bool LOCAL = false;
#else
constexpr bool LOCAL = true;
#endif

#define ll long long

int dr[] = {0,0,1,1,1,-1,-1,-1};
int dc[] = {1,-1,0,1,-1,0,1,-1};
// 글자 길이를 인덱스로 써서 바로 점수를 더할 수 있도록 하자.
// 길이가 0인 경우를 포함시켜야 하는 것 주의.
int scores[] = {0,0,0,1,1,2,3,5,11};

bool check[4][4];

struct Node {
  map<char, int> childs;
  bool valid;

  Node() {
    valid = false;
    for (int i = 0; i < 26; ++i) {
      childs[(char) (i + 'A')] = -1;
    }
  };
};

int init(vector<Node>& trie) {
  Node newNode;
  trie.push_back(newNode);
  return (int) trie.size() - 1;
}

void add(vector<Node>& trie, int root, string& str, int idx) {
  if (idx >= str.length()) {
    trie[root].valid = true;
    return;
  }

  char ch = str[idx];
  int& nextRoot = trie[root].childs[ch];

  if (nextRoot == -1) {
    int next = init(trie);
    nextRoot = next;
  }

  add(trie, nextRoot, str, idx + 1);
}

void search(
  int r,
  int c,
  vector<Node>& trie,
  int root,
  vector<string>& map,
  vector<string>& words,
  string str
) {
  if (r < 0 || c < 0 || r >= 4 || c >= 4) return;
  if (check[r][c]) return;
  if (str.length() >= 8) return;
  check[r][c] = true;

  int nextRoot = trie[root].childs[map[r][c]];
  if (nextRoot == -1) {
    check[r][c] = false;
    return;
  }

  str += map[r][c];
  if (trie[nextRoot].valid) {
    words.push_back(str);
  }

  for (int k = 0; k < 8; ++k) {
    int nr = r + dr[k];
    int nc = c + dc[k];
    search(nr, nc, trie, nextRoot, map, words, str);
  }

  check[r][c] = false;
}

int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int W;
  cin >> W;

  vector<Node> trie;
  int root = init(trie);

  for (int i = 0; i < W; ++i) {
    string str;
    cin >> str;
    add(trie, root, str, 0);
  }

  int B;
  cin >> B;
  while (B--) {
    vector<string> map(4);
    // 찾은 문자열들은 다 아래 배열에 넣자.
    vector<string> words;

    memset(check, 0, sizeof check);

    for (int i = 0; i < 4; ++i) {
      cin >> map[i];
    }

    // 매 시작점에서 완전탐색을 돌리자.
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        search(i, j, trie, root, map, words, "");
      }
    }

    // 중복 제거
    sort(words.begin(), words.end());
    words.erase(unique(words.begin(), words.end()), words.end());

    int score = 0;
    string longest = "";
    int cnt = 0;

    for (auto& word : words) {
      score += scores[word.length()];
      ++cnt;
      if (longest.length() < word.length()) {
        longest = word;
      }
      // 단어의 길이가 같다면 사전 순 정렬로 찾아야 한다.
      // 사전 순으로 가장 길이가 긴 문자열은 단순한 값 비교로 찾을 수 있다.
      else if (longest.length() == word.length() && longest > word) {
        longest = word;
      }
    }

    cout << score << ' ' << longest << ' ' << cnt << "\n";
  }

  return 0;
}