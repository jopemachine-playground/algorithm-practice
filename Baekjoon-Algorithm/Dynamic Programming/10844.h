/*
==============================+===============================================================
@ File Name : 10844.h
@ Author : jopemachine
@ Desc : 
@    쉬운 계단수
@    점화식을 도저히 찾을 수가 없었다. 점화식을 만들 때, n번째 길이의 계단 수 갯수를 
@    뒤에 어떤 숫자가 오는지에 따라 케이스를 나누기 위해, 이차원 배열로 만들면 점화식이 구해진다.
@ Ref URLs : 
@    https://js1jj2sk3.tistory.com/38
==============================+===============================================================
*/
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

long dp[101][10];
int mod = 1000000000;

void solve(){
    int N;
    cin >> N;

    // base case
    dp[1][0] = 0;
    for(int i = 1; i <= 9; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i <= N; i++){
        for(int j = 0; j <= 9; j++){
            if      (j == 0) dp[i][j] = (dp[i-1][j+1]) % mod;
            else if (j == 9) dp[i][j] = (dp[i-1][j-1]) % mod;
            else             dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
        }
    }

    long sum = 0;
//    cout << accumulate(dp[N], dp[N] + 10, 0);

    for (int elem: dp[N]){
        sum = (sum + elem) % mod;
    }

    cout << sum;
}
