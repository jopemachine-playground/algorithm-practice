#pragma once
#include <iostream>
#include "../Utility.h"

#define DEBUG_SORT

template<class T>
void selectionSort(T collection, int length, int (*comparator)(void* a, void* b)) {

	int index;
	auto selector = collection[0];

	for (int i = 0; i < length; i++) {
		index = i;
		selector = collection[i];

#ifdef DEBUG_SORT
		std::cout << i << "th step : \n";
#endif

		for (int j = i + 1; j < length; j++) {

			if (comparator(&selector, &collection[j]) == 1) {
				index = j;
				selector = collection[j];
			}

#ifdef DEBUG_SORT
			for (int k = 0; k < length; k++) {
				std::cout << collection[k] << " ";
			}
			std::cout << "\n";
#endif
		}

#ifdef DEBUG_SORT
		std::cout << "\n";
#endif

		swap(collection[i], collection[index]);
	}
}

// Min과 Max를 동시에 채우는 방식으로 개선된 선택 정렬
template<class T>
void minMaxSort(T collection, int length, int (*comparator)(void* a, void* b)) {

}

void test_selectionSort() {
	int* a = new int[10]{ 88, 33, 222, 77, 11, 33, 0, 99, 33 ,66 };
	selectionSort(a, 10, descending_compare);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
};