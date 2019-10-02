/*
==============================+===============================================================
@ File Name : 4344.h
@ Author : jopemachine
==============================+===============================================================
*/
#include <iostream>
#include <algorithm>
#include <array>
#include <set>
#include <numeric>
#include <vector>

using namespace std;

void solve(){

    int C;
    cin >> C;

    while(C-- > 0){

        vector<int> vec;
        int N, inp;
        cin >> N;

        for(int i = 0; i < N; i++){
            cin >> inp;
            vec.push_back(inp);
        }

        double avg = accumulate(vec.begin(), vec.end(), 0) / vec.size();

        int cntMoreThanAvg = 0;

        for_each(vec.begin(), vec.end(), [avg, &cntMoreThanAvg](int elem) -> void { if(elem > avg) cntMoreThanAvg++; });

        cout.precision(3);
        cout << fixed << ((double) cntMoreThanAvg / vec.size()) * 100 << "%\n";
    }
}

