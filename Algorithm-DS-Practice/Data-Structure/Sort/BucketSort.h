#pragma once
#include <memory>
#include <iostream>
#include <cmath>
#include <list>
#include "../Utility.h"

// int만 인자로 받을 수 있다
void bucketSort(int* intArray, int length, int maxRadix, int (*comparator)(void* a, void* b)) {

    // 동일한 크기의 링크드 리스트 배열을 만든다.
    std::list<int> *lists = new std::list<int>[length];

    // 나눌 값을 구함
    int dividor = (int) pow(10, maxRadix);

    // 어떤 버켓에 들어가야 하는지 판단하고, 넣는다
    for(int i = 0; i < length; i++){

        int findIndex = (intArray[i] * length) / dividor;

        // 버킷에 다른 원소가 있다면 그것들끼리 모두 크기를 비교해야 하므로,
        // 최악의 경우 O(n^2) 까지 효율이 떨어진다 (모든 원소가 같은 버킷에 있는 경우)
        std::list<int>::iterator insertIter;

        for(insertIter = lists[findIndex].begin(); insertIter != lists[findIndex].end(); insertIter++){
            if(intArray[i] < *insertIter){
                break;
            }
        }

        lists[findIndex].insert(insertIter, intArray[i]);
    }

    // 버켓에 있는 모든 수들을 꺼내서 원래 배열에 넣는다.
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