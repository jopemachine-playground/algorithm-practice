#include <iostream>
#include <vector>
using namespace std;
long long sum (vector<int>& arr) {
  long long sum = 0;
  for (auto i: arr) {
    sum += i;
  }
  return sum;
}
