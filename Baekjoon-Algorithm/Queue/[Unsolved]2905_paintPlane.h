//
// Created by wonma on 2019-06-30.
//

/*
############################################################################
############################################################################
############################################################################
############################### Fail #######################################
############################################################################
############################################################################
############################################################################
*/

#ifndef ALGORITHM_UNSOLVED_2905_PAINTPLANE_H
#define ALGORITHM_UNSOLVED_2905_PAINTPLANE_H

#include <iostream>
#include <string>
#include <queue>

using namespace std;

// 어떻게 큐로 푸는 건지 감이 안 잡혀서 검색해봤더니
// 그냥 큐가 아니라, monotone 우선순위 큐라는 것으로 푸는 문제라고 한다.
// 구글에 검색해도 자료가 거의 없고, 그 설명을 읽어봐도 이해가 안 가서 일단 포기.
// https://jaimemin.tistory.com/832

void solve_2905() {
    // (1 ≤ N ≤ 1000000)
    int heightNumber;
    // (1 ≤ X ≤ 100000)
    int brushWidth;
    cin >> heightNumber >> brushWidth;

    int* heightInputs = new int[heightNumber];

    for(int i = 0; i < heightNumber; i++){
        cin >> heightInputs[i];
    }

    int planeNumber;

    if(heightNumber % brushWidth == 0){
        planeNumber = heightNumber / brushWidth;
    }
    else{
        if(heightNumber < brushWidth){
            planeNumber = 0;
        }
        else{
            planeNumber = (heightNumber / brushWidth) + 1;
        }
    }



}



#endif //ALGORITHM_UNSOLVED_2905_PAINTPLANE_H
