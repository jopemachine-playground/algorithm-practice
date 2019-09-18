#ifndef ALGORITHM_2438_H
#define ALGORITHM_2438_H

#include <iostream>

using namespace std;

void solve_2438(){

    int N;
    cin >> N;
    int i = 1;
    while (N-- > 0){
        for(int j = 0; j < i; j++){
            cout << "*";
        }
        cout << "\n";
        ++i;
    }
}

#endif //ALGORITHM_2438_H
