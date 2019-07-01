#pragma once
#include <memory>
#include <iostream>
#include "../Utility.h"

template<class V, class T = V[], class Allocator = std::allocator<V>>
void merge(T a, T b, int (*comparator)(void* a, void* b));

template<class V, class T = V[], class Allocator = std::allocator<V>>
void split(T collection, int length, int (*comparator)(void* a, void* b)) {

	if (length <= 1) { return; }

	// ¦���� ��, ��Ȯ�ϰ� ������ ��������,
	// Ȧ���� ��, ������ �迭�� �� ���� �� ���� ���°� �ȴ�.
	int left_length = length / 2;
	int right_length = (length % 2 == 0) ? left_length : left_length + 1;

	Allocator allocator;

	// ���� �迭�� ������ �迭�� ������ ����
	V* left = allocator.allocate(left_length);
	V* right = allocator.allocate(right_length);

	// �迭 ������ ����
	for (int i = 0; i < left_length; i++) {
		left[i] = collection[i];
	}
	for (int i = 0; i < right_length; i++) {
		right[i] = collection[left_length + i];
	}

	// �� �迭�� ���� merge ȣ��� split
	split<V>(left, left_length, comparator);
	split<V>(right, right_length, comparator);

	//split(right, right_length, comparator);
	merge<V>(left, right, comparator);

}

template<class V, class T = V[], class Allocator = std::allocator<V>>
void mergeSort(T collection, int length, int (*comparator)(void* a, void* b)) {
	split<V>(collection, length, comparator);
}

template<class V, class T, class Allocator = std::allocator<V>>
void merge(T a, T b, int (*comparator)(void* a, void* b)) {


}

void test_mergeSort() {
	int* a = new int[10]{ 88, 33, 222, 77, 11, 33, 0, 99, 33 ,66 };
	mergeSort<int>(a, 10, ascending_compare);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
};