/*
==============================+===============================================================
@ File Name : 10952.h
@ Author : jopemachine
==============================+===============================================================
*/
#ifndef ALGORITHM_10952_H
#define ALGORITHM_10952_H

#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>

using namespace std;

void solve_10952(){
    int A, B;

    while(true){
        cin >> A >> B;
        if(A == 0 && B == 0) break;
        cout << A + B << "\n";
    }
}

#endif //ALGORITHM_10952_H
