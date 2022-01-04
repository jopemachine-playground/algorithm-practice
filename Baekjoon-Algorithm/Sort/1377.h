/*
==============================+===============================================================
@ File Name : 1377_bubbleSort.h
@ Author : jopemachine
@ Desc : 
@    ** Fail **
@    버블 소트
@    풀다 만 문제. 생각보다 어려운 개념을 요구했음.
==============================+===============================================================
*/

#ifndef ALGORITHM_1377_BUBBLESORT_H
#define ALGORITHM_1377_BUBBLESORT_H

#include <iostream>

using namespace std;

int swapNumber = 0;

int compare(const void* a, const void* b)
{
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 > num2) {
        swapNumber++;
        return -1;
    }

    if (num1 < num2) {
        swapNumber++;
        return 1;
    }

    return 0;
}

void solve_1377(){

    int n;
    cin >> n;
    int* a = new int[n + 1];

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    // quick sort
    qsort(a, n, sizeof(int), compare);

    cout << swapNumber;

}

#endif //ALGORITHM_1377_BUBBLESORT_H
