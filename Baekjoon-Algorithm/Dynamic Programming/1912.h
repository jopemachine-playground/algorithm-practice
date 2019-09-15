/*
==============================+===============================================================
@ File Name : 1912.h
@ Author : jopemachine
@ Desc : 
@    연속합
@    짜고 나니 정말 간단했지만, 어떻게 풀 수 있는지 잘 보이지 않았던 문제
@    반복문에서 지금 원소가 0보다 작을 때 Sum을 현재 input으로 초기화 해 주면 풀린다.
==============================+===============================================================
*/
#ifndef ALGORITHM_1912_H
#define ALGORITHM_1912_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

void solve_1912(){

    int N;
    cin >> N;

    int inputs[N];
    int maxSerialSum[N];

    for(int i = 0; i < N; i++) {
        cin >> inputs[i];
    }

    maxSerialSum[0] = inputs[0];

    for(int i = 1; i < N; i++) {
        if(maxSerialSum[i-1] >= 0){
            maxSerialSum[i] = maxSerialSum[i-1] + inputs[i];
        }
        else {
            maxSerialSum[i] = inputs[i];
        }
    }

    cout << *max_element(maxSerialSum, maxSerialSum + N);

}

void solve_1912_timeout(){

    int N;
    cin >> N;

    int inputs[N];

    for(int i = 0; i < N; i++) {
        cin >> inputs[i];
    }

    int max = -1001;
    // ** Timeout **
    for(int i = 0; i < N; i++) {
        int sum = inputs[i];
        for(int j = i + 1; j < N; j++){
            sum += inputs[j];
            if(max < sum){
                max = sum;
            }
        }
    }

    cout << max;

}

#endif //ALGORITHM_1912_H
