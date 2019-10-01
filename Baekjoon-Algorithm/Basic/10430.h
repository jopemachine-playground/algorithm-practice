/*
==============================+===============================================================
@ File Name : 10430.h
@ Author : jopemachine
==============================+===============================================================
*/
#ifndef ALGORITHM_10430_H
#define ALGORITHM_10430_H

#include <iostream>

using namespace std;

void solve_10430(){
    int A, B, C;

    cin >> A >> B >> C;

    printf("%d\n", (A+B)%C);
    printf("%d\n", (A%C+B%C)%C);
    printf("%d\n", (A*B)%C);
    printf("%d\n", (A%C*B%C)%C);

}
#endif //ALGORITHM_10430_H
