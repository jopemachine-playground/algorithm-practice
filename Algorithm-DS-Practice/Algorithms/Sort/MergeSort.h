#pragma once
#include <memory>
#include <iostream>
#include "../Utility.h"

// 아래 MergeSort는 C, C++로 배우는 자료구조론의 MergeSort 파트를 공부하며 작성한 것임

template<class V, class T = V[], class Allocator = std::allocator<V>>
void merge(T collection, int first, int middle, int last, int (*comparator)(void* a, void* b)){

    Allocator* allocator = new Allocator();
    T temp = allocator->allocate(last - first + 1);

    int leftFirst = first;
    int leftLast = middle;

    int rightFirst = middle + 1;
    int rightLast = last;

    int index = leftFirst;

    while(leftFirst <= leftLast && rightFirst <= rightLast){

        if(collection[leftFirst] < collection[rightFirst]){
            temp[index] = collection[leftFirst];
            ++leftFirst;
        }
        else {
            temp[index] = collection[rightFirst];
            ++rightFirst;
        }
        ++index;
    }

    while(leftFirst <= leftLast){
        temp[index] = collection[leftFirst];
        ++leftFirst;
        ++index;
    }

    while(rightFirst <= rightLast){
        temp[index] = collection[rightFirst];
        ++rightFirst;
        ++index;
    }

    for(index = first; index <= last; ++index){
        collection[index] = temp[index];
    }
}

template<class V, class T = V[], class Allocator = std::allocator<V>>
void split(T collection, int first, int last, int (*comparator)(void* a, void* b)) {

    // Base Case인 경우 아무 일도 하지 않고 리턴
    if(first < last){
        int middlePivot = (first + last) / 2;
        split<V>(collection, first, middlePivot, comparator);
        split<V>(collection, middlePivot + 1, last, comparator);
        merge<V>(collection, first, middlePivot, last, comparator);
    }

}

template<class V, class T = V[], class Allocator = std::allocator<V>>
void mergeSort(T collection, int length, int (*comparator)(void* a, void* b)) {
	split<V>(collection, 0, length - 1, comparator);
}

void test_mergeSort() {
	int* a = new int[10]{ 88, 33, 222, 77, 11, 33, 0, 99, 33 ,66 };
	mergeSort<int>(a, 10, ascending_compare);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
};