#ifndef ALGORITHM_2439_H
#define ALGORITHM_2439_H

#include <iostream>

using namespace std;

void solve_2439() {

    int N;
    cin >> N;
    int i = 1;
    while (N > 0) {

        for (int j = 0; j < N - 1; j++) cout << " ";
        for (int j = 0; j < i; j++)     cout << "*";

        cout << "\n";

        ++i; --N;
    }
}


#endif //ALGORITHM_2439_H
