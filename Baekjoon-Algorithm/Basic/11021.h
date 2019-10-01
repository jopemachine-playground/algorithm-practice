/*
==============================+===============================================================
@ File Name : 11021.h
@ Author : jopemachine
==============================+===============================================================
*/
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <cstdio>

using namespace std;
void solve_11021(){
    int A, B, T;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> A >> B;
        cout << "Case #" << i + 1 << ": " << A + B << "\n";
    }
}

