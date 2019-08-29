/*
==============================+===============================================================
@ File Name : 11047_coin.h
@ Author : jopemachine
@ Desc : 
@    동전 0
@    간단하게 풀 수 있는 문제.
==============================+===============================================================
*/

#ifndef SELFMADE_ALGORITHM_11047_COIN_H
#define SELFMADE_ALGORITHM_11047_COIN_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>

using namespace std;

void solve_11047(){

    int N, K;

    int res = 0;

    cin >> N >> K;

    int* pay_unit = new int[N];

    for(int i = 0; i < N; i++){
        cin >> pay_unit[i];
    }

    for(int i = N; i > 0; i--){
        int temp = pay_unit[i - 1];
        if(K / pay_unit[i - 1] >= 1){
            res += K / pay_unit[i - 1];
            K -= (K / pay_unit[i - 1]) * pay_unit[i - 1];
        }
    }

    cout << res;
}

#endif //SELFMADE_ALGORITHM_11047_COIN_H
