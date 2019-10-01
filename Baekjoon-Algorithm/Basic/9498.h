/*
==============================+===============================================================
@ File Name : 9498.h
@ Author : jopemachine
==============================+===============================================================
*/
#ifndef ALGORITHM_9498_H
#define ALGORITHM_9498_H

#include <iostream>
using namespace std;

void solve_9498(){
    int grade;

    cin >> grade;

    if     (90 <= grade && grade <= 100) cout << "A";
    else if(80 <= grade && grade <= 89 ) cout << "B";
    else if(70 <= grade && grade <= 79 ) cout << "C";
    else if(60 <= grade && grade <= 69 ) cout << "D";
    else cout << "F";

}


#endif //ALGORITHM_9498_H
