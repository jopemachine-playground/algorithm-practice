/*
==============================+===============================================================
@ Title : 재귀함수가 뭔가요?
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

int N;

string statements[] = {
  "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
  "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
  "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""
};

string finalStatement = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";

void print(int depth) {
  if (depth > N) return;

  string prefix = "";
  for (int i = 0; i < depth; ++i) {
    prefix += "____";
  }

  cout << prefix << "\"재귀함수가 뭔가요?\"" << "\n";

  if (depth == N) {
    cout << prefix << finalStatement << "\n";
  }
  else {
    for (string statement : statements) {
      cout << prefix << statement << "\n";
    }

    print(depth + 1);
  }

  cout << prefix << "라고 답변하였지."<< "\n";
}

int solve() {
  _FASTIOS;

  cin >> N;
  cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << "\n";
  print(0);

  return 0;
}
