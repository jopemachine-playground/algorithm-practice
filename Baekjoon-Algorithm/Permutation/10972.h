/*
==============================+===============================================================
@ File Name : 10972.h
@ Author : jopemachine
@ Desc : 
@    다음 순열
@    is_sorted, next_permutation의 사용법을 익혀두자. 
@    당연히 STL을 쓰지 않고 푸는 방법도 있다.
@ Ref URLs : 
@    https://kwanghyuk.tistory.com/25
==============================+===============================================================
*/
#ifndef ALGORITHM_10972_H
#define ALGORITHM_10972_H

#include <algorithm>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

template<class T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void solve_10972(){
    int N;
    cin >> N;
    int arr[N];
    string input = "";
    vector<string> permutations;

    for (int i = 0; i < N; i++) {
        string t;
        cin >> t;
        input += t + " ";
        arr[i] = i + 1;
    }

}

void solve_10972_bySTL(){

    int N;
    cin >> N;
    int inputs[N];

    for(int i = 0; i < N; i++){
        cin >> inputs[i];
    }

    if(is_sorted(&inputs[0], &inputs[N], [](int x, int y) { return x > y; })) {
        cout << -1;
    }

    else{
        next_permutation(inputs, inputs + N);

        for (int i = 0; i < N; i++) {
            cout << inputs[i] << " ";
        }
    }
}


#endif //ALGORITHM_10972_H
