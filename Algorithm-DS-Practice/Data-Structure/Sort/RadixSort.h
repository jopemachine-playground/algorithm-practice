#pragma once
#include <memory>
#include <iostream>
#include <cmath>
#include "../Utility.h"

// int�� ���ڷ� ���� �� �ִ�
void radixSort(int* intArray, int length, int radixLength, int (*comparator)(void* a, void* b)) {

    int * radixCount = new int[10];
    int * temp = new int[length];

    for(int i = 0; i < 10; i++){
        radixCount[i] = 0;
    }

    // radix Length (d) ��ŭ �ݺ�
    for(int i = 0; i < radixLength; i++){
        // length (n) ��ŭ �ݺ�
        for(int j = 0; j < length; j++){

            // i��° radixNumber
            int nthRadix = (intArray[j] % (int) pow(10, (double) i + 1)) / (int) pow(10, (double) i);

            radixCount[nthRadix]++;
        }

        // radixCount�� ���� �������� ���� ������
        for(int j = 0; j < 10; j++){
            radixCount[j + 1] += radixCount[j];
        }

        // ���� radixCount ���� ������ �� ���� �ڸ����� ���� �����ϰ�
        // ���� �ڸ����� �Ѿ
        for(int j = length - 1; j >= 0; j--){
            int nthRadix = (intArray[j] % (int) pow(10, (double) i + 1)) / (int) pow(10, (double) i);
            temp[--radixCount[nthRadix]] = intArray[j];
        }

        // temp�� intArray�� ����
        for(int j = 0; j < length; j++){
            intArray[j] = temp[j];
        }

        // �ʱ�ȭ
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