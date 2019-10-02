/*
==============================+===============================================================
@ File Name : 1932.h
@ Author : jopemachine
@ Desc : 
@    정수 삼각형
@    뒤에서 부터 생각해야 했던 문제. 메모이제이션할 배열은 i 번째 레벨의 j번째 수로,
@    이차원 배열로 생각해야 한다. 그럼 i 번째 레벨의 j번째 수는
@    i-1번째 수의 j-1번째 수 (위 레벨의 왼쪽 DP 값) 과 i번째 수의 j번째 수 (위 레벨의 
@    오른쪽 DP 값) 중 큰 수에 arr[i][j]를 더해준 값이 된다.
==============================+===============================================================
*/
#include <iostream>

using namespace std;

const int MAX = 501;

int arr[MAX][MAX];
int  dp[MAX][MAX];

void solve(){
    int N;
    cin >> N;

    int max = -1;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= i; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= N; i++){
        for (int j = 1; j <= i; j++){
            int leftDP  = dp[i-1][j-1] + arr[i][j];
            int rightDP = dp[i-1][j]   + arr[i][j];

            dp[i][j] = leftDP > rightDP ? leftDP : rightDP;
            if (dp[i][j] > max) max = dp[i][j];
        }
    }

    cout << max;
}
