#ifndef ALGORITHM_2750_H
#define ALGORITHM_2750_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(){
    int N;
    cin >> N;
    vector<int> inputs;
    int a;

    while(N-- > 0){
        cin >> a;
        inputs.push_back(a);
    }

    sort(inputs.begin(), inputs.end(), less<int>());

    for_each(inputs.begin(), inputs.end(), [](int elem) -> void { cout << elem << "\n"; });
}

#endif //ALGORITHM_2750_H
