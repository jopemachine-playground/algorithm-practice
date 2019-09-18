#ifndef ALBOAITHM_10817_H
#define ALBOAITHM_10817_H

#include <iostream>

using namespace std;

void solve_10817(){
    int A, B, C;
    cin >> A >> B >> C;

    int res;
    if((A <= B && A >= C) || (A >= B && A <= C)){
        res = A;
    }
    else if((B <= A && B >= C) || (B >= A && B <= C)){
        res = B;
    }
    else res = C;

    cout << res;
}
#endif //ALBOAITHM_10817_H
