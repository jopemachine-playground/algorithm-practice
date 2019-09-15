/*
==============================+===============================================================
@ File Name : 2217.h
@ Author : jopemachine
@ Desc : 
@    로프
==============================+===============================================================
*/

#ifndef ALGORITHM_2217_H
#define ALGORITHM_2217_H

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <algorithm>

using namespace std;

int ascendingCompare(const void* a, const void* b)
{
    int num1 = *(int*) a;
    int num2 = *(int*) b;

    if (num1 > num2)
        return 1;
    else if (num1 < num2)
        return -1;
    else return 0;
}

void solve_2217(){

    int N;
    cin >> N;

    int *ropes = new int[N];

    for(int i= 0; i < N; i++){
        scanf("%d", &ropes[i]);
    }

    qsort( ropes, N, sizeof(int), ascendingCompare );

//    for(int i= 0; i < N; i++){
//        printf("%d\n", ropes[i]);
//    }

    int *W = new int[N];

    for(int i = 0; i < N; i++){
        W[i] = (i + 1) * ropes[N-i-1];
    }

    cout << *max_element(W, W + N);

    delete W;
    delete ropes;
}

#endif //ALGORITHM_2217_H
