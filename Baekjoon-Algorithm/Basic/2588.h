/*
==============================+===============================================================
@ File Name : 2588.h
@ Author : jopemachine
==============================+===============================================================
*/
#ifndef ALGORITHM_2588_H
#define ALGORITHM_2588_H

#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;
void solve_2588(){
    string A, B;
    int X3, X4, X5, X6;

    cin >> A;
    cin >> B;

    X3 = atoi(A.c_str()) * (B[2] - '0');
    X4 = atoi(A.c_str()) * (B[1] - '0');
    X5 = atoi(A.c_str()) * (B[0] - '0');
    X6 = atoi(A.c_str()) * atoi(B.c_str());

    cout << X3 << "\n";
    cout << X4 << "\n";
    cout << X5 << "\n";
    cout << X6 << "\n";

}
#endif //ALGORITHM_2588_H
