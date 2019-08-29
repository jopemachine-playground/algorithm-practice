/*
==============================+===============================================================
@ File Name : 1992.h
@ Author : jopemachine
@ Desc : 
@    쿼드트리
@    문제 출력이 복잡해보이는데, divide란 함수를 정의해놓고 분할정복으로 푸니 간단했다.
==============================+===============================================================
*/


#ifndef ALGORITHM_1992_H
#define ALGORITHM_1992_H

#include <iostream>
#include <memory.h>

using namespace std;

int** map;

void divide(int** map, int begin_x, int end_x, int begin_y, int end_y){

    int hits_black = 0;
    int hits_white = 0;

    for (int y = begin_y; y <= end_y; y++){
        for (int x = begin_x; x <= end_x; x++){
            if(hits_black != 0 && hits_white != 0) goto recur;
            if(map[y][x] == 1) hits_black++;
            else               hits_white++;
        }
    }

    recur:

    // All white
    if(hits_black == 0){
        cout << "0";
    }

    // All blue
    else if(hits_white == 0){
        cout << "1";
    }
        // divide by recursive
    else{

        cout << "(";

        divide(map,  begin_x                   , (begin_x + end_x) / 2, begin_y                    , (begin_y + end_y) / 2);

        divide(map, ((begin_x + end_x) / 2) + 1, end_x                , begin_y                    , (begin_y + end_y) / 2);

        divide(map,  begin_x                   , (begin_x + end_x) / 2, ((begin_y + end_y) / 2 + 1), end_y    );

        divide(map, ((begin_x + end_x )/ 2) + 1, end_x                , ((begin_y + end_y) / 2 + 1), end_y    );

        cout << ")";
    }
}

void solve_1930(){

    int N;
    cin >> N;

    map = new int* [N];

    string *map_oneline = new string[N];

    for(int i = 0; i < N; i++){
        map[i] = new int[N];
        memset(map[i], 0, sizeof(int) * N);
    }

    for (int i = 0; i < N; i++) {
        cin >> map_oneline[i];

        for (int j = 0; j < N; j++) {
            map[i][j] = map_oneline[i].at(j) - 48;
        }
    }

    divide(map, 0, N - 1, 0, N - 1);

};

#endif //ALGORITHM_1992_H
