/*
==============================+===============================================================
@ File Name : 2748.h
@ Author : jopemachine
==============================+===============================================================
*/
#ifndef ALGORITHM_2748_H
#define ALGORITHM_2748_H

#include <iostream>

using namespace std;

void solve_2748(){
    long long int n;
    cin >> n;
    long long int f[n + 1];

    f[0] = 0; f[1]= 1;
    for (int i = 2; i <= n; i++){
        f[i] = f[i-1] + f[i-2];
    }

    cout << f[n];
}
#endif //ALGORITHM_2748_H
