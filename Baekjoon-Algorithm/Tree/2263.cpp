#include <cstdio>

int inorder[100000];
int postorder[100000];
// inorder의 숫자가 어디에서 왔는지 기록.
// 1부터 시작하기 때문에 1 늘림.
int position[100001];

// 매번 slice로 vector를 전달하는게 아니라 인덱스들만을 전달해야 메모리 초과를 피할 수 있음에 주의.
// 이렇게 스트링이나 리스트를 분할할 때 그 자체를 쪼개서 전달하는게 아니라 인덱스만 변경해서 전달하는 방법을 기억해두자.
void solve(int inorder_s, int inorder_e, int postorder_s, int postorder_e) {
  // 범위 초과
  if (inorder_s > inorder_e || postorder_s > postorder_e) return;

  int root = postorder[postorder_e];

  // 전위 출력이니까 root를 바로 출력
  printf("%d ", root);

  // inorder의 인덱스를 O(1)로 반환
  int inorderRootIdx = position[root];

  // rootIdx에 이동한 정도
  int left = inorderRootIdx - inorder_s;

  solve(
    inorder_s, inorderRootIdx - 1,
    postorder_s, postorder_s + left - 1
  );

  solve(
    inorderRootIdx + 1, inorder_e,
    postorder_s + left, postorder_e - 1
  );
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &inorder[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &postorder[i]);
  // inorder의 숫자가 어디서 왔는지 기록해준다.
  for (int i = 0; i < n; ++i) position[inorder[i]] = i;

  solve(0, n - 1, 0, n - 1);
  return 0;
}