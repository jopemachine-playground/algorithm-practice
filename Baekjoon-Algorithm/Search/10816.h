// 백준 알고리즘 강의 중급
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findUpperbound (int* arr, int arrLen, int target) {
  int start = 0;
  int end = arrLen - 1;

  int ans = -1;
  while (start <= end) {
    int mid = (start + end) / 2;

    // 상한은 큰 수 중 제일 작은 인덱스에 있는 수
    if (arr[mid] == target) {
      ans = mid + 1;
      start = mid + 1;
    } else if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return ans;
}

int findLowerbound (int* arr, int arrLen, int target) {
  int start = 0;
  int end = arrLen - 1;

  int ans = -1;
  while (start <= end) {
    int mid = (start + end) / 2;

    if (arr[mid] == target) {
      // 주의 : 상한과 다르게 하한은 크거나 *같은* 수 중에서 제일 작은 인덱스에 있는 수이다.
      ans = mid;
      end = mid - 1;
    } else if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return ans;
}

int solve() {
  int N, M;
  cin >> N;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int cards[500000];

  for (int i = 0; i < N; ++i) {
    cin >> cards[i];
  }

  sort(cards, cards + N);

  cin >> M;

  while (M--) {
    int next;
    cin >> next;
    int upperbound = findUpperbound(cards, N, next);
    int lowerbound = findLowerbound(cards, N, next);
    // 상한 - 하한 : 해당 수의 갯수
    printf("%d ", upperbound - lowerbound);
  }

  return 0;
}