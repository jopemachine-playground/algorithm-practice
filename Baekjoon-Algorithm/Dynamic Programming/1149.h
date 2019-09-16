/*
==============================+===============================================================
@ File Name : 1149.h
@ Author : jopemachine
==============================+===============================================================
*/
#ifndef ALGORITHM_1149_H
#define ALGORITHM_1149_H


#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef struct{
    int R;
    int G;
    int B;

    void min(){
        int res;
        if(R <= G && R <= B){
            res = R;
        }
        else if(G <= R && G <= B){
            res = G;
        }
        else res = B;
    }

    void mid(){

        int res;
        if(R <= G && R >= B){
            res = R;
        }
        else if(G <= R && G >= B){
            res = G;
        }
        else res = B;
    }

} Color;

void solve_1149(){
    int N;
    cin >> N;
    Color colorArr[N];

    int prevInx = -1;
    int F[N];
    for (int i = 0; i < N; i++){
        cin >> colorArr[i].R >> colorArr[i].G >> colorArr[i].B;


    }




}

#endif //ALGORITHM_1149_H
