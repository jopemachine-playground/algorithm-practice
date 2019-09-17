#ifndef ALGORITHM_2753_H
#define ALGORITHM_2753_H

#include <iostream>
using namespace std;

void solve_2753(){
    int N;
    cin >> N;
    auto cond_A = [](int N) -> bool { return !(N % 4);};
    auto cond_B = [](int N) -> bool { return N % 100;};
    auto cond_C = [](int N) -> bool { return !(N % 400);};

    if(cond_A(N) && cond_B(N) || cond_A(N) && cond_C(N))
        cout << 1;
    else cout << 0;
}

#endif //ALGORITHM_2753_H
