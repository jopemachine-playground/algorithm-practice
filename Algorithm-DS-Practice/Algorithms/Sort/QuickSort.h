#pragma once
#include <memory>
#include <iostream>
#include "../Utility.h"

// 아래 QuickSort는 C, C++로 배우는 자료구조론의 QuickSort 파트를 공부하며 작성한 것임

template<class V, class T = V[], class Allocator = std::allocator<V>>
int split(T collection, int first, int last, int (*comparator)(void* a, void* b)){

    // 업포인터는 피벗보다 큰 값을, 다운 포인터는 피벗보다 작은 값을 찾아 교체한다.
    int upPointer = first;
    int downPointer = last - 1;
    V pivot = collection[last];

    // 두 포인터가 교차하면 빠져나감
    while(upPointer <= downPointer){
        while(pivot > collection[upPointer]) upPointer++;
        while(pivot <= collection[downPointer]) downPointer--;

        if(upPointer <= downPointer) swap(collection[upPointer], collection[downPointer]);
    }

    swap(collection[upPointer], collection[last]);
    return upPointer;
}

template<class V, class T = V[], class Allocator = std::allocator<V>>
void sort(T collection, int first, int last, int (*comparator)(void* a, void* b)) {

    // Base Case인 경우 아무 일도 하지 않고 리턴
    if(first < last){
        int pivotIndex = split<V>(collection, first, last, comparator);
        sort<V>(collection, first, pivotIndex - 1, comparator);
        sort<V>(collection, pivotIndex + 1, last, comparator);
    }

}

template<class V, class T = V[], class Allocator = std::allocator<V>>
void quickSort(T collection, int length, int (*comparator)(void* a, void* b)) {
    sort<V>(collection, 0, length - 1, comparator);
}

void test_quickSort() {
    int* a = new int[10]{ 88, 33, 222, 77, 11, 33, 0, 99, 33 ,66 };
    quickSort<int>(a, 10, ascending_compare);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }
};