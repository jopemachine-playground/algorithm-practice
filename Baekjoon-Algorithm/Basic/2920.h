#ifndef ALGORITHM_2920_H
#define ALGORITHM_2920_H

#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <cstdio>

using namespace std;
void solve_2920(){

    int A[8];
    for (int i = 0; i < 8; i++)
        cin >> A[i];
    bool isAscending  = is_sorted(&A[0], &A[8], [](int x, int y)-> bool{ return x < y;});
    bool isDescending = is_sorted(&A[0], &A[8], [](int x, int y)-> bool{ return x > y;});

    if(isAscending){
        cout << "ascending";
    }
    else if(isDescending){
        cout << "descending";
    }
    else cout << "mixed";

}

#endif //ALGORITHM_2920_H
