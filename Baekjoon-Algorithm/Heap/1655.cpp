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

// int main() {
int solve() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;

  // 최대 힙
  priority_queue<int> que1;
  // 최소 힙
  priority_queue<int, vector<int>, greater<int>> que2;

  for (int i = 0; i < N; ++i) {
    int num;
    cin >> num;
    // 큐 1의 최댓값보다 작은 값인 경우
    if (que1.size() <= 0 || que1.top() > num) {
      que1.push(num);
    }
    // 큐 1의 최댓값보다 큰 경우
    else {
      que2.push(num);
    }

    // 서로 N/2개가 되도록 맞춰준다.
    // 홀수라서 N/2이 될 수 없다면 que1이 1 더 커야 한다.
    while (
      (que1.size() != que2.size()) &&
      (que1.size() != que2.size() + 1)
    ){
      // 큐 1의 사이즈가 더 큰 경우 큐 1에서 빼고 큐 2에 넣는다.
      if (que1.size() > que2.size()) {
        int top = que1.top();
        que1.pop();
        que2.push(top);
      }
      else if (que1.size() < que2.size()) {
        int top = que2.top();
        que2.pop();
        que1.push(top);
      }
    }
    
    // 그렇게 하면 큐 1의 마지막 원소 (최댓값)가 중간값이 된다.
    cout << que1.top() << "\n";
  }

  return 0;
}