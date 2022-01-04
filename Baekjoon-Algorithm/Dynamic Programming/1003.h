/*
==============================+===============================================================
@ File Name : 1003_Fibonacci.h
@ Author : jopemachine
@ Desc : 
@    피보나치 함수
@    DP 기초 문제. cacheZero, cacheOne이란 int형 배열 2개를 만들어 반복문에서 주어진 input을 만드는데,
@    이용했다.
==============================+===============================================================
*/

#ifndef ALGORITHM_1003_FIBONACCI_H
#define ALGORITHM_1003_FIBONACCI_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

void solve_1003() {
    // 0 <= N <= 40
    int inputN;
    cin >> inputN;

    int* inputs = new int[inputN];

    int maxInput = 0;

    for(int i = 0; i < inputN; i++){
        cin >> inputs[i];
        if(maxInput < inputs[i]) maxInput = inputs[i];
    }

    int* cacheZero = new int[maxInput + 1];
    int* cacheOne = new int[maxInput + 1];

    cacheZero[0] = 1;
    cacheOne[0] = 0;

    cacheZero[1] = 0;
    cacheOne[1] = 1;

    for(int i = 2; i <= maxInput; i++){
        cacheZero[i] = cacheZero[i-1] + cacheZero[i-2];
        cacheOne[i] = cacheOne[i-1] + cacheOne[i-2];
    }

    for(int i = 0; i < inputN; i++){
        cout << cacheZero[inputs[i]] << " " << cacheOne[inputs[i]] << "\n";
    }

}


#endif //ALGORITHM_1003_FIBONACCI_H
