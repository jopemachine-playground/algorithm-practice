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

// ��� ť�� Ǫ�� ���� ���� �� ������ �˻��غô���
// �׳� ť�� �ƴ϶�, monotone �켱���� ť��� ������ Ǫ�� ������� �Ѵ�.
// ���ۿ� �˻��ص� �ڷᰡ ���� ����, �� ������ �о���� ���ذ� �� ���� �ϴ� ����.
// https://jaimemin.tistory.com/832

void solve_2905() {
    // (1 �� N �� 1000000)
    int heightNumber;
    // (1 �� X �� 100000)
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
