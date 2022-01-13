#include <iostream>

using namespace std;

void printStar(int i, int j, int unit) {
  if (
    ((i / unit) % 3 == 1) &&
    ((j / unit) % 3 == 1)
  ) {
    cout << " ";
  } else if (unit == 1) {
    cout << "*";
  } else {
    printStar(i, j, unit / 3);
  }
}

int solve () {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;

  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      printStar(i, j, N);
    }
    cout << "\n";
  }
  return 0;
}