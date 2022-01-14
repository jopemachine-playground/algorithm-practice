#pragma once
#include <memory>
#include <iostream>
#include <cmath>
#include <list>
#include "../Utility.h"

// int�� ���ڷ� ���� �� �ִ�
void bucketSort(int* intArray, int length, int maxRadix, int (*comparator)(void* a, void* b)) {

    // ������ ũ���� ��ũ�� ����Ʈ �迭�� ������.
    std::list<int> *lists = new std::list<int>[length];

    // ���� ���� ����
    int dividor = (int) pow(10, maxRadix);

    // � ���Ͽ� ����� �ϴ��� �Ǵ��ϰ�, �ִ´�
    for(int i = 0; i < length; i++){

        int findIndex = (intArray[i] * length) / dividor;

        // ��Ŷ�� �ٸ� ���Ұ� �ִٸ� �װ͵鳢�� ���� ũ�⸦ �����ؾ� �ϹǷ�,
        // �־��� ���� O(n^2) ���� ȿ���� �������� (���� ���Ұ� ���� ��Ŷ�� �ִ� ����)
        std::list<int>::iterator insertIter;

        for(insertIter = lists[findIndex].begin(); insertIter != lists[findIndex].end(); insertIter++){
            if(intArray[i] < *insertIter){
                break;
            }
        }

        lists[findIndex].insert(insertIter, intArray[i]);
    }

    // ���Ͽ� �ִ� ���� ������ ������ ���� �迭�� �ִ´�.
    int index = 0;
    for(int i = 0; i < length; i++) {
        while (!lists[i].empty()) {
            intArray[index++] = lists[i].front();
            lists[i].pop_front();
        }
    }
}

void test_bucketSort() {
    int* a = new int[10]{ 188, 332, 222, 227, 121, 333, 100, 299, 343 ,626 };
    bucketSort(a, 10, 3, ascending_compare);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }
};
