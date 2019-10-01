/*
==============================+===============================================================
@ File Name : 8393.h
@ Author : jopemachine
==============================+===============================================================
*/
#ifndef ALGORITHM_8393_H
#define ALGORITHM_8393_H

#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>

using namespace std;

void solve_8393(){
    int N, R = 0;
    cin >> N;
    int A[N];

    for(int i = 0; i < N; i++) A[i]= i + 1;

    R = accumulate(A, A + N, R);

    cout << R;
}
#endif //ALGORITHM_8393_H
