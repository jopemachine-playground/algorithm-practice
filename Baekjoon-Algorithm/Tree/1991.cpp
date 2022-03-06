/*
==============================+===============================================================
@ Title : 트리 순회
@ Desc :
@ Ref :
==============================+===============================================================
*/

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

char childs[27][2];

void preorder(char node) {
  int idx = node - 'A';
  cout << node;

  if (childs[idx][0] != '.') {
    preorder(childs[idx][0]);
  }

  if (childs[idx][1] != '.') {
    preorder(childs[idx][1]);
  }
}

void inorder(char node) {
  int idx = node - 'A';

  if (childs[idx][0] != '.') {
    inorder(childs[idx][0]);
  }

  cout << node;

  if (childs[idx][1] != '.') {
    inorder(childs[idx][1]);
  }
}

void postorder(char node) {
  int idx = node - 'A';

  if (childs[idx][0] != '.') {
    postorder(childs[idx][0]);
  }

  if (childs[idx][1] != '.') {
    postorder(childs[idx][1]);
  }

  cout << node;
}

int solve() {
  _FASTIOS;
  int N;
  cin >> N;
  while (N--) {
    char curr, left, right;
    cin >> curr >> left >> right;
    childs[curr - 'A'][0] = left;
    childs[curr - 'A'][1] = right;
  }

  preorder('A');
  cout << '\n';
  inorder('A');
  cout << '\n';
  postorder('A');
  cout << '\n';

  return 0;
}