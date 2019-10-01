/*
==============================+===============================================================
@ File Name : 10818.h
@ Author : jopemachine
==============================+===============================================================
*/
#ifndef ALGORITHM_10818_H
#define ALGORITHM_10818_H

#include <algorithm>
#include <iostream>
using namespace std;

void solve_10818(){

    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    cout << *min_element(A, A + N) << " ";
    cout << *max_element(A, A + N);
}


#endif //ALGORITHM_10818_H
