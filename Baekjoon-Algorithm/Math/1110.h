#ifndef ALGORITHM_1110_H
#define ALGORITHM_1110_H

#include <iostream>

using namespace std;

void solve_1110(){
    string N;
    cin >> N;

    int dec1, dec2;
    int input = atoi(N.c_str());

    if(input < 10){
        dec1 = 0;
        dec2 = N.at(0) - '0';
    }
    else {
        dec1 = N.at(0) - '0';
        dec2 = N.at(1) - '0';
    }

    int R = 0;

    while(1){

        int temp = dec2;
        dec2 = (dec1 + dec2) % 10;
        dec1 = temp;
        int i = 10 * dec1 + dec2;

        if(input == 10 * dec1 + dec2){
            break;
        }

        R++;
    }

    cout << R + 1;

}

#endif //ALGORITHM_1110_H
