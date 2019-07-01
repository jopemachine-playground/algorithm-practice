#pragma once
#include <iostream>
#include "../Utility.h"

// ���� ������ �̿��� ���� ����.
template<class T>
void insertionSort_HalfSwap(T collection, int length, int (*comparator)(void* a, void* b)) {

	for (int i = 1; i < length; i++) {

		int pick = i + 1;
		auto temp = collection[i];

		for (int j = i ; j > 0 && comparator(&collection[j - 1], &temp) == 1; j--) {
			collection[j] = collection[j - 1];
			pick = j;
		}

		collection[pick - 1] = temp;
	}
}

// Ǯ ������ �̿��� ���� ����. ���� ���� swap�� �̷����� ������, ��ȿ������.
template<class T>
void insertionSort_FullSwap(T collection, int length, int (*comparator)(void* a, void* b)) {
	for (int i = 1; i < length; i++) {
		for (int j = i; j > 0 && comparator(&collection[j - 1], &collection[j]) == 1; j--) {
			swap(collection[j - 1], collection[j]);
		}
	}
}

void test_insertionSort() {
	int* a = new int[10]{ 88, 33, 222, 77, 11, 33, 0, 99, 33 ,66 };
	insertionSort_HalfSwap(a, 10, ascending_compare);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
};