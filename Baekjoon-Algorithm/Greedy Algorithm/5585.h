/*
==============================+===============================================================
@ File Name : 5585.h
@ Author : jopemachine
@ Desc : 
@    거스름돈
==============================+===============================================================
*/

#ifndef ALGORITHM_5585_H
#define ALGORITHM_5585_H

#include <iostream>
using namespace std;

void solve_5585(){
    // int < 1000
    int in;

    cin >> in;

    in = 1000 - in;
    int bill500 = (in / 500);
    in -= bill500 * 500;
    int bill100 = (in / 100);
    in -= bill100 * 100;
    int bill50  = (in / 50 );
    in -= bill50 * 50;
    int bill10  = (in / 10 );
    in -= bill10 * 10;
    int bill5   = (in / 5  );
    in -= bill5 * 5;
    int bill1   = (in / 1  );

    cout << bill500 + bill100 + bill50 + bill10 + bill5 + bill1;
}


#endif //ALGORITHM_5585_H
