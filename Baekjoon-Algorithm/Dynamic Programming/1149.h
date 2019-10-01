/*
==============================+===============================================================
@ File Name : 1149.h
@ Author : jopemachine
==============================+===============================================================
*/
#ifndef ALGORITHM_1149_H
#define ALGORITHM_1149_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

int cost[1001][3];
int   dp[1001][3];

void solve(){
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> cost[i][0];
        cin >> cost[i][1];
        cin >> cost[i][2];
    }

    for(int i = 1; i <= N; i++) {
        dp[i][0] = dp[i-1][1] > dp[i-1][2] ? cost[i][0] + dp[i-1][2] : cost[i][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0] > dp[i-1][2] ? cost[i][1] + dp[i-1][2] : cost[i][1] + dp[i-1][0];
        dp[i][2] = dp[i-1][1] > dp[i-1][0] ? cost[i][2] + dp[i-1][0] : cost[i][2] + dp[i-1][1];
    }

    cout << *min_element(dp[N], dp[N] + 3);

}

#endif //ALGORITHM_1149_H
