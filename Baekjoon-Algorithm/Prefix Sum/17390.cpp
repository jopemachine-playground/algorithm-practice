#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long> calcPartialSum (vector<int>& arr) {
  vector<long> res {arr[0]};
  for (int i = 1; i < arr.size(); ++i) {
    res.push_back(res[i - 1] + arr[i]);
  }
  return res;
}

// int main () {
int solve () {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, Q;
  cin >> N >> Q;

  vector<int> vec(N);
  for (auto& i : vec) {
    cin >> i;
  }

  sort(vec.begin(), vec.end());

  vector<long> partialSum = calcPartialSum(vec);

  for (int i = 0; i < Q; ++i) {
    int start, end;
    cin >> start >> end;

    if (start - 1 == 0) {
      cout << partialSum[end - 1] << "\n";
    } else {
      cout << (partialSum[end - 1] - partialSum[start - 2]) << "\n";
    }
  }

  return 0;
}