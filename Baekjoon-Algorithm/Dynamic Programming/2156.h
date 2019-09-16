/*
==============================+===============================================================
@ File Name : 2156.h
@ Author : jopemachine
@ Desc : 
@    포도주 시식
@    계단 오르기와 거의 똑같은 문제. 다만 이 문제에선, 반복문에서 i 번째 포도주를 마시지 않는다는 선택지를
@    함께 고려해야 한다.
==============================+===============================================================
*/
#ifndef ALGORITHM_2156_H
#define ALGORITHM_2156_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <algorithm>

using namespace std;

void solve_2156(){
    int N;
    cin >> N;

    int wines[N + 1];
    int maxWines[N + 1];
    wines[0] = 0;
    for(int i = 1; i < N + 1; i++){
        cin >> wines[i];
    }

    maxWines[0] = 0;
    maxWines[1] = wines[1];
    maxWines[2] = wines[1] + wines[2];

    int cases[3];
    for(int i = 3; i < N + 1; i++){

        cases[0] = wines[i] + maxWines[i-2];
        cases[1] = wines[i] + wines[i-1] + maxWines[i-3];
        cases[2] = maxWines[i-1];

        maxWines[i] = *max_element(cases, cases + 3);
    }

    cout << *max_element(maxWines, maxWines + (N + 1));

}

#endif //ALGORITHM_2156_H
