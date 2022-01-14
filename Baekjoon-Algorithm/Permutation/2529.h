#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check (vector<int>& perms, vector<char>& oprs) {
  for (int i = 0; i < oprs.size(); ++i) {
    if (oprs[i] == '<' && perms[i] > perms[i + 1]) return false;
    if (oprs[i] == '>' && perms[i] < perms[i + 1]) return false;
  }

  return true;
}

void print(vector<int>& vec) {
  for (int item : vec) {
    cout << item;
  }
  cout << endl;
}

int solve() {
  int k;
  cin >> k;

  vector<int> small(k + 1);
  vector<int> big(k + 1);
  vector<char> oprs(k);

  for (int i = 0; i <= k; ++i) {
    small[i] = i;
    big[i] = 9 - i;
    cin >> oprs[i];
  }

  do {
    if (check(big, oprs)) {
      print(big);
      break;
    }
  } while(prev_permutation(big.begin(), big.end()));

  do {
    if (check(small, oprs)) {
      print(small);
      break;
    }
  } while(next_permutation(small.begin(), small.end()));

  return 0;
}