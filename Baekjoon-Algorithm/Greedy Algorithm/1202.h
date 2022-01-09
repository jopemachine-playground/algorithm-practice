// 백준 알고리즘 중급 강좌, BST 이용한 풀이
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct jewel {
  int weight, value;
};

int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  
  vector<jewel> jewels(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d %d", &jewels[i].weight, &jewels[i].value);
  }

  // 가격 내림 차순으로 정렬
  sort(jewels.begin(), jewels.end(), [](jewel u, jewel v) {
    return u.value > v.value;
  });

  // 가방의 무게를 BST에 삽입
  multiset<int> set;

  for (int i = 0; i < K; ++i) {
    int t;
    scanf("%d", &t);
    set.insert(t);
  }

  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    // 각 보석의 무게 보다 큰 제일 작은 값을 리턴.
    auto it = set.lower_bound(jewels[i].weight);

    if (it != set.end()) {
      ans += jewels[i].value;
      set.erase(it);
    }
  }

  printf("%lld\n", ans);
  return 0;
}