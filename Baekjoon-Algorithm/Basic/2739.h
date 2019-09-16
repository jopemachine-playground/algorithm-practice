#ifndef ALGORITHM_2739_H
#define ALGORITHM_2739_H

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <cstdio>

using namespace std;
void solve_2739(){
    int N;
    cin >> N;
    for(int i = 1; i < 10; i++){
        printf("%d * %d = %d\n" , N, i, N * i);
    }

};
#endif //ALGORITHM_2739_H
