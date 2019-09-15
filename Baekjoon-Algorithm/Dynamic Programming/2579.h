/*
==============================+===============================================================
@ File Name : 2579.h
@ Author : jopemachine
@ Desc : 
@    ** Fail **
@    계단 오르기
==============================+===============================================================
*/
#ifndef ALGORITHM_2579_H
#define ALGORITHM_2579_H

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

void solve_2579(){

    int N;

    cin >> N;

    int scores[N + 1];
    int stairs[N + 1];

    scores[0] = 0;
    stairs[0] = 0;

    for (int i = 1; i <= N; i++){
        cin >> scores[i];
        stairs[i] = 0;
    }

    stairs[1] = scores[1];
    stairs[2] = scores[1] + scores[2];

    for (int i = 3; i <= N; i++){

        int candidate_A = scores[i] + scores[i-1] + stairs[i-3];
        int candidate_B = scores[i] + stairs[i-2];

        stairs[i] = candidate_A > candidate_B ? candidate_A : candidate_B;
    }

    cout << stairs[N];

}

#endif //ALGORITHM_2579_H
