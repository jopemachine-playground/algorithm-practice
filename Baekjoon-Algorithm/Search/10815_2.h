#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int solve() {
  int N, M;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // BST
  set<int> cards;

  cin >> N;
  for (int i = 0; i < N; ++i) {
    int next;
    cin >> next;
    cards.insert(next);
  }

  cin >> M;

  for (int i = 0; i < M; ++i) {
    int next;
    cin >> next;
    auto it = cards.find(next);

    if (it != cards.end()) {
      printf("1 ");
    }
    else {
      printf("0 ");
    }
  }

  return 0;
}