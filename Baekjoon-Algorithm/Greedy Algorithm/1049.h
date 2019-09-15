/*
==============================+===============================================================
@ File Name : 1049.h
@ Author : jopemachine
@ Desc : 
@    기타줄
@    패키지의 최소 가격과 낱개의 최소 가격을 구한 후 최소 가격으로 살 수 있는 케이스를 3개 나눠 그 중 최소값을 구하니
@    쉽게 풀 수 있었다
==============================+===============================================================
*/
#ifndef ALGORITHM_1049_H
#define ALGORITHM_1049_H

#include <algorithm>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>

using namespace std;

void solve_1049(){
    int N, M;

    cin >> N >> M;

    int packagePrices[M];
    int   piecePrices[M];

    for(int i = 0; i < M; i++){
        cin >> packagePrices[i] >> piecePrices[i];
    }

    int min_packagePrice = *min_element(packagePrices, packagePrices + M);
    int   min_piecePrice = *min_element(  piecePrices,   piecePrices + M);

    int cases[3];

    cases[0] = (N / 6) * min_packagePrice + (N - ((N / 6) * 6)) * min_piecePrice;
    cases[1] = ((N / 6) + 1) * min_packagePrice;
    cases[2] = N * min_piecePrice;

    cout << *min_element(cases, cases + 3);

}

#endif //ALGORITHM_1049_H
