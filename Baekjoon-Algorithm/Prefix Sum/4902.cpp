#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getRowPartialSums(vector<vector<int>>& map) {
  vector<vector<int>> res(map.size());

  for (int i = 0; i < map.size(); ++i) {
    int sum = 0;
    res[i].resize(map[i].size());

    for (int j = 0; j < map[i].size(); ++j) {
      sum += map[i][j];
      res[i][j] = sum;
    }
  }
  return res;
}

int getPrefixSum(vector<int>& partialSum, int left, int right) {
  return left == 0 ? (partialSum[right]) : (partialSum[right] - partialSum[left - 1]);
}

// int main() {
int solve() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int testIdx = 1;
  int lineCnt = -1;

  while (true) {
    cin >> lineCnt;
    if (lineCnt == 0) break;

    vector<vector<int>> map(lineCnt);

    for (int i = 1; i <= lineCnt; ++i) {
      for (int j = 0; j < 2 * i - 1; ++j) {
        int num;
        cin >> num;
        map[i - 1].push_back(num);
      }
    }

    int result = -100000;

    vector<vector<int>> partialRowSums = getRowPartialSums(map);

    for (int i = 0; i < map.size(); ++i) {
      for (int j = 0; j < map[i].size(); ++j) {
        // cout << "-----------------------------" << "\n";
        // cout << "i: " << i << "\n";
        // cout << "j: " << j << "\n";

        int h = i + 1;
        int left = j;
        int right = j + 2;
        int sum = map[i][left];
        if (sum > result) result = sum;

        // 정방향 삼각형
        if (j % 2 == 0) {
          while (
            h < lineCnt &&
            right < map[h].size()
          ) {
            sum += getPrefixSum(partialRowSums[h], left, right);

            if (sum > result) result = sum;

            right = right + 2;
            h++;
          }
        }

        // cout << "sum: " << sum << "\n";
      }
    }

    for (int i = map.size() - 1; i >= 0; --i) {
      for (int j = 0; j < map[i].size(); ++j) {
        int h = i - 1;
        int left = j - 2;
        int right = j;
        int sum = map[i][right];
        if (sum > result) result = sum;

        // 역방향 삼각형
        if (j % 2 == 1) {
          // cout << "-----------------------------" << "\n";
          // cout << "i: " << i << "\n";
          // cout << "j: " << j << "\n";

          while (
            h >= 0 &&
            left >= 0 &&
            map[h].size() > right
          ) {
            sum += getPrefixSum(partialRowSums[h], left, right);

            if (sum > result) result = sum;

            left = left - 2;
            h--;
          }

          // cout << "sum: " << sum << "\n";
        }
      }
    }

    cout << testIdx++ << ". " << result << "\n";
  }

  return 0;
}