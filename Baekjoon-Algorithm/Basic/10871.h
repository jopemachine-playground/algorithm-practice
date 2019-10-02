/*
==============================+===============================================================
@ File Name : 10871.h
@ Author : jopemachine
==============================+===============================================================
*/
#ifndef ALGORITHM_10871_H
#define ALGORITHM_10871_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(){
    int N, X;
    cin >> N >> X;

    vector<int> inp;
    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        inp.push_back(input);
    }

    vector<int> res;
    copy_if(inp.cbegin(), inp.cend(), back_inserter(res), [X](int x)->bool { return x < X;});
    for_each(res.cbegin(), res.cend(), [](int x)-> void { cout << x << " "; });

}

#endif //ALGORITHM_10871_H
