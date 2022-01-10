#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int find (int* arr, int arrLen, int target) {
  int start = 0;
  int end = arrLen - 1;

  int mid;
  while (start <= end) {
    mid = (start + end) / 2;

    if (arr[mid] == target) {
      return mid;
    }

    if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return -1;
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
    int idx = find(cards, N, next);
    if (idx != -1) {
      printf("1 ");
    }
    else {
      printf("0 ");
    }
  }

  return 0;
}