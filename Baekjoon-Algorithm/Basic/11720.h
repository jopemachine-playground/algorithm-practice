/*
==============================+===============================================================
@ File Name : 11720.h
@ Author : jopemachine
==============================+===============================================================
*/
#ifndef ALGORITHM_11654_H
#define ALGORITHM_11654_H

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <cstdio>

using namespace std;

void solve_11720(){
    int N;
    cin >> N;

    string input;
    cin >> input;
    int R = 0;
    for(int i = 0; i < N; i++){
        R += (input[i] - '0');
    }
    cout << R;

}

#endif //ALGORITHM_11654_H
