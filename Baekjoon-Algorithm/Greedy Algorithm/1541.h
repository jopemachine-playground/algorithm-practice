/*
==============================+===============================================================
@ File Name : 1541.h
@ Author : jopemachine
@ Desc : 
@    잃어버린 괄호
@    한 번 마이너스가 나오면 그 뒤는 전부 뺄셈으로 처리하면 된다.
@    c++엔 split이 없어서 필요할 때 구현해야 된다. 구현을 잘 알아두도록 하자.
@ Ref URLs : 
@    https://twinw.tistory.com/220
==============================+===============================================================
*/
#ifndef ALGORITHM_1541_H
#define ALGORITHM_1541_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimeter){
    vector<string> internal;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimeter)){
        internal.push_back(temp);
    }
    return internal;
}

void solve_1541(){
    string input;
    cin >> input;

    int R = 0;
    vector<string> elems;
    elems = split(input, '-');

    string plus  = elems[0];
    vector<string> plusElems = split(plus, '+');
    for (string& elem : plusElems){
        R += atoi(elem.c_str());
    }

    // Minus Elem
    for (int i = 1; i < elems.size(); i++){

        string minus = elems[i];

        vector<string> minusElems = split(minus, '+');
        for(string& elem : minusElems){
            R -= atoi(elem.c_str());
        }
    }

    cout << R;
}

#endif //ALGORITHM_1541_H
