/*
==============================+===============================================================
@ File Name : 2577.h
@ Author : jopemachine
==============================+===============================================================
*/
#ifndef ALGORITHM_2577_H
#define ALGORITHM_2577_H

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int countNumber(const string& str, int x){
    return count(str.begin(), str.end(), x + '0');
}

void solve(){
    int A, B, C;
    cin >> A >> B >> C;
    const int X = A * B * C;
    const string input = to_string(X);

    for (int i = 0; i <= 9; i++){
        cout << countNumber(input, i) << "\n";
    }

}
#endif //ALGORITHM_2577_H
