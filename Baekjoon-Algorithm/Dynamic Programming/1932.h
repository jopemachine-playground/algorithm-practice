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
