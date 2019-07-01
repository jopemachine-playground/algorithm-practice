#pragma once
#include <iostream>
#include "../Utility.h"

template<class T>
void shellSort(T collection, int length, int (*comparator)(void* a, void* b)) {
	

}

void test_insertionSort() {
	int* a = new int[10]{ 88, 33, 222, 77, 11, 33, 0, 99, 33 ,66 };
	shellSort(a, 10, ascending_compare);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
};