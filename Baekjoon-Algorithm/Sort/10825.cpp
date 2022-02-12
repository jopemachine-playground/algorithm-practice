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

struct Student {
  string name;
  int score1, score2, score3;
};

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;

  vector<Student> students(N);

  for (int i = 0; i < N; ++i) {
    cin >> students[i].name >> students[i].score1 >> students[i].score2>> students[i].score3;
  }

  sort(students.begin(), students.end(), [](const Student& u, const Student& v) {
    if (u.score1 > v.score1) {
      return true;
    } else if (u.score1 < v.score1) {
      return false;
    }

    if (u.score2 > v.score2) {
      return false;
    } else if (u.score2 < v.score2) {
      return true;
    }

    if (u.score3 > v.score3) {
      return true;
    } else if (u.score3 < v.score3) {
      return false;
    }

    return u.name < v.name;
  });

  for (int i = 0; i < N; ++i) {
    cout << students[i].name << "\n";
  }

  return 0;
}