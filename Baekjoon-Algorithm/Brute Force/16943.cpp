#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

vector<int> getSeq(int k) {
  vector<int> res;

  while (k > 0) {
    res.push_back(k % 10);
    k /= 10;
  }

  return res;
}

int getNumber(vector<int>& seq) {
  int result = 0;
  for (int i = 0; i < seq.size(); ++i) {
    result += seq[i] * ((int) pow(10, seq.size() - i - 1));
  }
  return result;
}

int solve() {
  int A, B;
  cin >> A >> B;

  // 원래 reverse 해 줘야 되는데 어차피 내림차순 정렬할 거라 의미 없음.
  vector<int> seq = getSeq(A);

  sort(seq.begin(), seq.end(), greater<int>());

  int result = -1;

  do {
    if (seq[0] == 0) continue;
    int num = getNumber(seq);

    if (num < B) {
      result = num;
      break;
    }
  } while (prev_permutation(seq.begin(), seq.end()));

  cout << result << "\n";
  return 0;
}