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
  // 0, 1을 나타내는 자식 2개만 있으면 된다.
  int childs[2];
  bool valid;
  Node() {
    for (int i = 0; i < 2; ++i) {
      childs[i] = -1;
    }
    valid = false;
  }
};

vector<Node> trie;

int addNode() {
  Node x;
  trie.push_back(x);
  return (int) trie.size() - 1;
}

// 트라이에서 string 쓰던 것을 int로 대체,
// index 쓰던 것 대신 bit로 대체.
// bit는 32에서 시작해 1씩 더 작은 숫자로 내려감.
void add(int node, int num, int bit) {
  if (bit == -1) {
    trie[node].valid = true;
    return;
  }

  // num이 bit 자리에 1이 켜져 있는가를 나타냄.
  int c = (num >> bit) & 1;
  if (trie[node].childs[c] == -1) {
    int next = addNode();
    trie[node].childs[c] = next;
  }

  add(trie[node].childs[c], num, bit - 1);
}

int query(int node, int num, int bit) {
  assert(bit != -1);
  if (bit == -1) return 0;
  int c = (num >> bit) & 1;

  // xor를 최대로 만들기 위해 num의 해당 비트와 다른 비트를 써야 한다.
  c = 1 - c;
  // 못 찾으면 어쩔 수 없이 원래 비트를 써야 한다.
  // 다시 되돌려 주기 위해, 다시 한 번 토글한다.
  if (trie[node].childs[c] == -1) {
    c = 1 - c;
  }

  // 나올 수 없는 경우: 0과 1 자식이 만들어지지 않음.
  assert(trie[node].childs[c] != -1);
  if (trie[node].childs[c] == -1) {
    return 0;
  }

  // bit번째 비트를 결정하고 bit-1번째 비트를 결정하기 위해 재귀호출
  int next = c == 1 ? (1 << bit) : 0;
  return next | query(trie[node].childs[c], num, bit - 1);
}

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N;

  cin >> N;

  int trieRoot = addNode();
  vector<int> nums(N);

  int ans = 0;

  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
    add(trieRoot, nums[i], 31);
  }

  for (int i = 0; i < N; ++i) {
    int res = query(trieRoot, nums[i], 31) ^ nums[i];
    if (ans < res) ans = res;
  }

  cout << ans << "\n";

  return 0;
}