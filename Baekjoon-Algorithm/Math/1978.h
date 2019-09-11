#ifndef ALGORITHM_1978_H
#define ALGORITHM_1978_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve_1978(){

    int N, R;

    // root(1000) = 31.622..
    int primesLessThan32[] = {
            2,  3,  5,  7,
            11, 13, 17, 19,
            23, 29,
            31
    };

    cin >> N;
    int inputs[N];

    int allNumbers[1001];

    // 1 is not prime number
    allNumbers[0] = -1;
    allNumbers[1] = -1;
    for(int i = 2; i <= 1000; i++){
        allNumbers[i] = i;
    }

    vector<int> primes;

    for (int i = 0; i < N; i++) {
        cin >> inputs[i];
    }

    for (int i = 0; i < sizeof(primesLessThan32) / sizeof(int); i++){
        // primes.push_back(primesLessThan32[i]);
        int multipleOfPrime = primesLessThan32[i];
        int k = 2;
        while((multipleOfPrime * k) <= 1000){
            allNumbers[multipleOfPrime * k] = -1;
            k++;
        }
    }

    for(int i = 1; i <= 1000; i++){
        if(allNumbers[i] == -1) continue;
        primes.push_back(allNumbers[i]);
    }

    R = N;
    for(int i = 0; i < N; i++){
        vector<int>::iterator iter = find(primes.begin(), primes.end(), inputs[i]);
        if(iter == primes.end()){
            R--;
        }
    }

    cout << R;


}


#endif //ALGORITHM_1978_H
