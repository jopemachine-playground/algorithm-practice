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
