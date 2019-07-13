#pragma once
#include <memory>
#include <iostream>
#include "../Utility.h"

// �Ʒ� QuickSort�� C, C++�� ���� �ڷᱸ������ QuickSort ��Ʈ�� �����ϸ� �ۼ��� ����

template<class V, class T = V[], class Allocator = std::allocator<V>>
int split(T collection, int first, int last, int (*comparator)(void* a, void* b)){

    // �������ʹ� �ǹ����� ū ����, �ٿ� �����ʹ� �ǹ����� ���� ���� ã�� ��ü�Ѵ�.
    int upPointer = first;
    int downPointer = last - 1;
    V pivot = collection[last];

    // �� �����Ͱ� �����ϸ� ��������
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

    // Base Case�� ��� �ƹ� �ϵ� ���� �ʰ� ����
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