// 백준 중급 알고리즘 강의
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  int N;
  cin >> N;

  vector<int> vec;
  for (int i = 0; i < N; ++i) {
    int n;
    cin >> n;

    // 지금까지 들어왔던 입력들 중 n보다 큰 가장 작은 값을 찾는다.
    auto it = lower_bound(vec.begin(), vec.end(), n);

    // 최댓값인 경우
    if (it == vec.end()) {
      vec.push_back(n);
    } else {
      *it = n;
    }
  }

  cout << vec.size();
}