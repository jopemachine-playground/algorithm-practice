#ifndef ALGORITHM_3052_H
#define ALGORITHM_3052_H

#include <iostream>
#include <array>
#include <set>

using namespace std;

void solve(){
    array<int, 10> input;
    set<int> inputSet;

    for (int i = 0; i < 10; i++){
        cin >> input[i];
        inputSet.insert(input[i] % 42);
    }
    cout << inputSet.size();

}
#endif //ALGORITHM_3052_H
