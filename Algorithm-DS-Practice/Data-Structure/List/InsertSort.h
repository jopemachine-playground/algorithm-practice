#pragma once
#include <iostream>
#include "../Utility.h"

template<class T>
void selectSort(T collection, int length, int (*comparator)(void* a, void* b)) {
	
	int index;
	auto selector = collection[0];

	for (int i = 0; i < length; i++) {
		index = i;

		for (int j = i + 1; j < length; j++) {
			if (comparator(&selector, &collection[j]) == 1) {
				index = j;
			}
		}

		swap(collection[i], collection[index]);
	}
}

void test_selectSort() {
	int* a = new int[10]{ 88, 33, 222, 77, 11, 33, 0, 99, 33 ,66 };
	insertionSort(a, 10, ascending_compare);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
};