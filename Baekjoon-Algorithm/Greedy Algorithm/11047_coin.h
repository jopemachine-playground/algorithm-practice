//
// Created by wonma on 2019-07-01.
//

#ifndef SELFMADE_ALGORITHM_11047_COIN_H
#define SELFMADE_ALGORITHM_11047_COIN_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>

using namespace std;

void solve_11047(){

    // (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)
    int N, K;

    // 필요한 동전 갯수
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
