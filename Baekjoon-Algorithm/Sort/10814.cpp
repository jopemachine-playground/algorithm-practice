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

struct Person {
  int age;
  string name;
};

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  
  vector<Person> persons(N);
  for (int i = 0; i < N; ++i) {
    cin >> persons[i].age >> persons[i].name;
  }

  // 나이 순으로 정렬하면 알아서 가입 순서대로 정렬되도록 안정 정렬을 쓰자.
  // (참조 쓸거면 const를 반드시 붙여줘야 한다.)
  stable_sort(persons.begin(), persons.end(), [](const Person& u, const Person& v) {
    return u.age < v.age;
  });

  for (int i = 0; i < N; ++i) {
    cout << persons[i].age << ' ' << persons[i].name << "\n";
  }

  return 0;
}