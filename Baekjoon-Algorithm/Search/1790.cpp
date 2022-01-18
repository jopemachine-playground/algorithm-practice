// 백준 알고리즘 강의 중급
#include <iostream>

using namespace std;

// 1부터 num까지 문자열로 더했을 때의 자릿수 출력
long long calc (int num) {
  long long ans = 0;
  for (int start = 1, len = 1; start <= num; start *= 10, len++) {
    // len에 해당하는 숫자들이 꽉 차 있을 때의 갯수
    int end = start * 10 - 1;
    if (end > num) {
      end = num;
    }
    // end, start 둘 다 포함이니 1 더함
    ans += (long long) (end - start + 1) * len;
  }
  return ans;
}

int solve() {
  int N, K;
  cin >> N >> K;

  if (calc(N) < K) {
    cout << -1 << "\n";
    return 0;
  }

  int left = 0;
  int right = N;

  int ans = 0;

  long long k;
  // 이분 탐색으로 반 씩 쪼개면서 1부터 N까지 더했을 때의 자릿수를 보자.
  // 자릿수가 K가 될 때 까지 반복하면 몇 자리로 끝났는지 구할 수 있으니까.
  while (left <= right) {
    int mid = (left + right) / 2;
    k = calc(mid);

    if (k < K) {
      left = mid + 1;
    } else {
      right = mid - 1;
      ans = mid;
    }
  }

  string s = to_string(ans);
  long long l = calc(ans);

  cout << s[s.length() - 1 - (l - K)] << "\n";
  return 0;
}