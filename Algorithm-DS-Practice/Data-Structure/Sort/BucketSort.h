#pragma once
#include <memory>
#include <iostream>
#include <cmath>
#include <list>
#include "../Utility.h"

// int만 인자로 받을 수 있다
void bucketSort(int* intArray, int length, int maxRadix, int (*comparator)(void* a, void* b)) {

    // 동일한 크기의 링크드 리스트 배열을 만든다.
    std::list<int> lists[length];

    // 나눌 값을 구함
    int dividor = (int) pow(10, maxRadix);

    // 어떤 버켓에 들어가야 하는지 판단하고, 넣는다
    for(int i = 0; i < length; i++){
        lists[(intArray[i] * length) / dividor].push_back(intArray[i]);
    }

    // 버켓에 있는 모든 수들을 꺼내서 원래 배열에 넣는다.
    int index = 0;
    for(int i = 0; i < length; i++) {
        while (!lists[i].empty()) {
            intArray[index++] = lists->front();
            lists->pop_front();
        }
    }
}

void test_bucketSort() {
    int* a = new int[10]{ 188, 333, 222, 277, 121, 333, 100, 299, 343 ,626 };
    bucketSort(a, 10, 3, ascending_compare);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }
};