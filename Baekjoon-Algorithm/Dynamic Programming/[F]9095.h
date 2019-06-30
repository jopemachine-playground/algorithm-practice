//
// Created by wonma on 2019-06-29.
//

/*
############################################################################
############################################################################
############################################################################
############################### Fail #######################################
############################################################################
############################################################################
############################################################################
*/

#ifndef ALGORITHM_F_9095_H
#define ALGORITHM_F_9095_H

#pragma once
// to use unsafe function
#pragma warning(disable: 4996)

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

// https://nhs0912.tistory.com/62 참고
// 규칙에 대해 정확히 이해하지 못해서 점화식을 발견하지 못했다.
// 결국 검색해서, 내가 이해하지 못한 부분이 있단 것을 깨달았고,
// 점화식을 알게 되니 바로 풀 수 있었음
void solve_9095(){

    int n;
    cin >> n;

    int* inputs = new int[n];
    // n < 11
    array<int, 11> cache;

    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;

    int maxInput = 0;

    for(int i = 0; i < n; i++){
        cin >> inputs[i];
        if(inputs[i] > maxInput) maxInput = inputs[i];
    }

    for(int i = 4; i <= maxInput; i++){
        cache[i] = cache[i-1] + cache[i-2] + cache[i-3];
    }

    for(int i = 0; i < n; i++){
        cout << cache[inputs[i]] << "\n";
    }

}


#endif //ALGORITHM_F_9095_H


