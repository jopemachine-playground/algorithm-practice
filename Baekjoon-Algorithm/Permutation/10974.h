/*
==============================+===============================================================
@ File Name : 10974.h
@ Author : jopemachine
@ Desc : 
@    ** Fail **
@    모든 순열
@    dfs로 풀 수 있다는데 방법을 모르겠어서 찾아봤다. 찾아보고 dfs로 완전 탐색해서 
@    리프에 해당하는 값 들을 출력해 풀 수 있다는 걸 알게 되었다.
==============================+===============================================================
*/
#ifndef ALGORITHM_10974_H
#define ALGORITHM_10974_H

#include <algorithm>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

// min 1, max 8
int     N;

vector<string> vec;

template<class T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void dfs(int* arr, int n, int remain){

    if(remain == 0){
        string s = "";
        for(int i = 0; i < N; i++){
            s += std::to_string(arr[i]) + " ";
        }
        vec.push_back(s);
        return;
    }

    for(int i = n; i < N; i++){
        ::swap(arr[i], arr[n]);
        ::dfs(arr, n + 1, remain - 1);
        ::swap(arr[i], arr[n]);
    }
}

void solve_10974(){

    cin  >> N;
    int arr[N];

    for(int i = 0; i < N; i++){
        arr[i] = i + 1;
    }

    dfs(arr, 0, N);

    std::sort(vec.begin(), vec.end(), less<string>());

    for(auto& str : vec){
        cout << str << "\n";
    }

}
#endif //ALGORITHM_10974_H
