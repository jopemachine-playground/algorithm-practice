// 백준 알고리즘 강의 중급
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int getCnt(long long num, int k) {
  int cnt = 0;
  while (num % k == 0) {
    ++cnt;
    num /= k;
  }
  return cnt;
}

// int main() {
int solve() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  vector<pair<int, long long>> res(N);

  for (int i = 0; i < N; ++i) {
    cin >> res[i].second;
    

    // 2와 3의 갯수를 세서 3의 갯수에 대해 내림차순, 2의 갯수에 대해 오름차순으로 정렬하면 된다
    // 근데, 2의 갯수로 오름차순하는 건 숫자 자체에 대해 오름차순 하는 것과 같은 의미이므로
    // 그냥 3의 갯수에 대해 내림차순 정렬하면 된다.
    // c++에서 pair에 대해 정렬할 땐, 기본이 오름차순 정렬이고 이게 first와 second에 모두 들어가므로,
    // 첫 번째 값을 - 처리해주면 내림차순 -> 오름차순으로 정렬 가능하다. 
    res[i].first = -1 * getCnt(res[i].second, 3);
  }

  sort(res.begin(), res.end());

  for_each(res.begin(), res.end(), [](auto it) {
    cout << it.second << ' ';
  });

  return 0;
}