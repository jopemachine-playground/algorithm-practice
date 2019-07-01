#pragma once

#include <iostream>
#include "../Utility.h"

#define DEBUG_SORT

// T가 [], <, > 가 정의된 collection 이어야 작동한다
template<class T>
void bubbleSort(T collection, int length, int (*comparator)(void* a, void* b)) {
	
	bool isSorted = false;

	for (int i = length - 1; i > 0 && !isSorted; i--) {
		
		isSorted = true;
		
#ifdef DEBUG_SORT
		std::cout << (length - i)  << "th step : \n";
#endif
		for (int j = 0; j < i; j++) {

#ifdef DEBUG_SORT
			for (int k = 0; k < length; k++) {
				std::cout << collection[k] << " ";
			}
#endif
			if (comparator(&collection[j], &collection[j+1]) == 1) {
				swap(collection[j], collection[j+1]);
				isSorted = false;
			}
#ifdef DEBUG_SORT
			std::cout << "\n";
#endif
		}
#ifdef DEBUG_SORT
		std::cout << "\n";
#endif
	}
}

void test_bubbleSort() {
	int* a = new int[10]{ 88, 33, 222, 77, 11, 33, 0, 99, 33, 66 };
	bubbleSort(a, 10, ascending_compare);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
};