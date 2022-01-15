#include <vector>
#include <iostream>

using namespace std;

class PriorityQueue {
private:
  void swap(int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }

public:
  vector<int> arr;

  void push(int num) {
    arr.push_back(num);

    // 아래에서 시작해서..
    int idx = arr.size() - 1;
    int parentIdx = (idx - 1) / 2;
    while (parentIdx >= 0 && arr[parentIdx] < arr[idx]) {
      // 위가 더 클 때 까지 올림.
      swap(parentIdx, idx);
      idx = parentIdx;
      parentIdx = (idx - 1) / 2;
    }
  }

  int pop() {
    int result = arr[0];
    arr[0] = arr.back();
    arr.pop_back();

    int idx = 0;

    while (true) {
      int left = 2 * idx + 1;
      int right = 2 * idx + 2;
      int next = idx;

      if (left >= arr.size()) break;

      // 왼쪽 자식이 더 크다면
      if (arr[next] < arr[left]) {
        next = left;
      }

      // 오른쪽 자식이 더 크다면 (부모 뿐 아니라 왼쪽 자식과도 비교)
      if (right < arr.size() && arr[next] < arr[right]) {
        next = right;
      }

      if (next == idx) break;
      swap(next, idx);
      idx = next;
    }

    return result;
  }
};

int solve () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  auto pq = PriorityQueue();
  int N;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    int opr;
    cin >> opr;

    if (opr == 0 && pq.arr.size() == 0) {
      cout << 0 << "\n";
    } else if (opr == 0) {
      cout << pq.pop() << "\n";
    } else {
      pq.push(opr);
    }
  }
  return 0;
}