#pragma once
#include <memory>
#include <iostream>
#include <cmath>
#include "../Utility.h"

// int만 인자로 받을 수 있다
void radixSort(int* intArray, int length, int radixLength, int (*comparator)(void* a, void* b)) {

    int * radixCount = new int[10];
    int * temp = new int[length];

    for(int i = 0; i < 10; i++){
        radixCount[i] = 0;
    }

    // radix Length (d) 만큼 반복
    for(int i = 0; i < radixLength; i++){
        // length (n) 만큼 반복
        for(int j = 0; j < length; j++){

            // i번째 radixNumber
            int nthRadix = (intArray[j] % (int) pow(10, (double) i + 1)) / (int) pow(10, (double) i);

            radixCount[nthRadix]++;
        }

        // radixCount를 전부 누적시켜 값을 구하자
        for(int j = 0; j < 10; j++){
            radixCount[j + 1] += radixCount[j];
        }

        // 구한 radixCount 누적 값으로 한 개의 자릿수에 대해 정렬하고
        // 다음 자릿수로 넘어감
        for(int j = length - 1; j >= 0; j--){
            int nthRadix = (intArray[j] % (int) pow(10, (double) i + 1)) / (int) pow(10, (double) i);
            temp[--radixCount[nthRadix]] = intArray[j];
        }

        // temp를 intArray에 복사
        for(int j = 0; j < length; j++){
            intArray[j] = temp[j];
        }

        // 초기화
        for(int i = 0; i < 10; i++){
            radixCount[i] = 0;
        }

    }

}

void test_radixSort() {
    int* a = new int[10]{ 188, 333, 222, 277, 121, 333, 100, 299, 343 ,626 };
    radixSort(a, 10, 3, ascending_compare);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }
};