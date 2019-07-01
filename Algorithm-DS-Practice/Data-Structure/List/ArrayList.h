#pragma once
#include <memory>
#include <iostream>
#include "../MockClass.h"

const int ArrayList_Default_MAX = 100;

// ���ø��� ����ϱ� ������ ������Ͽ� ������ �����ؾ� �Ѵ�.

// https://docs.microsoft.com/ko-kr/cpp/standard-library/allocators?view=vs-2019#writing-your-own-allocator-c11
// �ܺο��� ������ Ÿ�� T�� ������ ������ �����Ƿ�, Allocator�� Ŭ������ Ȱ���� ��ü�� �����ؾ� �Ѵ�. 
// �� Ŭ������ new �����ڸ� ���� �ʰ�, malloc�� ����� ��ü�� �����Ѵ�
// ������, �Ʒ� template�� Vector Ŭ������ ���ø��� ������

template<class T, class Allocator = std::allocator<T>>
class ArrayList {
public:
	
	ArrayList() {
		count = 0;
		capacity = ArrayList_Default_MAX;
		arrayList = allocator->allocate(capacity);
	};

	ArrayList(int initial_Max) : capacity(initial_Max) {
		count = 0;
		arrayList = allocator->allocate(capacity);
	};

	ArrayList(const ArrayList& rhs) {
		count = rhs.count;
		capacity = rhs.capacity;
		arrayList = allocator->allocate(capacity);
		
		for (int i = 0; i < count; i++) {
			arrayList[i] = rhs.arrayList[i];
		}
	};

	~ArrayList() {
		delete arrayList;
		arrayList = nullptr;
	};

	T get(int index) {
		if (index > count) {
			throw std::out_of_range("range out of error");
		}
		else {
			return arrayList[index];
		}
	};

	bool remove(T item) {
		for (int i = 0; i < count; i++) {
			if (arrayList[i] == item) {
				removeByIndex(i);
				return true;
			}
		}
		return false;
	};

	bool removeByIndex(int index) {
		if (index > count) {
			throw std::out_of_range("range out of error");
			return false;
		}

		for (int i = index; i < count - index; i++) {
			arrayList[i] = arrayList[i + 1];
		}

		count--;
		return true;
	};

	bool add(T item) {
		arrayList[count++] = item;
		return true;
	};

	bool add(int index, T item) {
		if (index > count) {
			throw std::out_of_range("range out of error");
			return false;
		}

		for (int i = count - index; i >= index; i--) {
			arrayList[i + 1] = arrayList[i];
		}

		arrayList[index] = item;
		count++;
		return true;
	};

	bool isEmpty() {
		return count == 0;
	};

	int length() {
		return count;
	};

private:

	std::unique_ptr<Allocator> allocator;

	int count;

	int capacity;

	// �� �κп��� T arrayList[] �� �ƴ϶�, �����Ͱ� �;��Ѵٴ� �� �߿���
	// ���� �������� �򰥷ȴ� �κ��̴�, �� �˾Ƶ���
	// ���� �迭�� ���� ��, int *array = new int[length]; �� ���� 
	// int array[] = new int[length] �� ���� �ʴ´�.

	T* arrayList;
};

void ArrayList_test() {

	// ����Ʈ�� ����Ʈ �����۵鵵 ���ÿ� �ִ� ��� (�Ǵ� ������Ƽ�� Ÿ��) (case 1)
	ArrayList<int> ListStack_itemInt(10);

	// ����Ʈ��, ����Ʈ �����۵鵵 ���� �ִ� ��� (case 2)
	ArrayList<MockClass*>* ListHeap_itemHeap = new ArrayList<MockClass*>(10);

	// ����Ʈ�� ���ÿ�, ����Ʈ �����۵鵵 ���ÿ� ������, �����۵��� ��ü�� ��� (case 3)
	// case3�� �����ϱ� ���ؼ�, Allocator Ŭ������ Ȱ���� ArrayList�� �ۼ��ؾ߸� �Ѵ�.
	// Allocator�� �̿��� �ۼ��� Ŭ������, ���� T*�� �Ű��� �޴� �Լ����� �ۼ��� �ʿ䰡 ����.
	ArrayList<MockClass> ListStack_itemStack(10);

	// ����Ʈ�� ����, ����Ʈ �����۵��� ���ÿ� �ִ� ��� (case 4)
	ArrayList<MockClass>* ListHeap_itemStack = new ArrayList<MockClass>(10);


	// test case 1
	std::cout << "#### test case 1 ####" << std::endl;
	int a = 3;
	int b = 5;
	int c = 4;

	ListStack_itemInt.add(a);
	ListStack_itemInt.add(b);
	ListStack_itemInt.add(1, c);
	ListStack_itemInt.add(4);

	for (int i = 0; i < ListStack_itemInt.length(); i++) {
		std::cout << ListStack_itemInt.get(i) << std::endl;
	}

	// test case 2

	std::cout << "#### test case 2 ####" << std::endl;

	MockClass* b1 = new MockClass(3);
	MockClass* b2 = new MockClass(5);
	MockClass* b3 = new MockClass(4);

	ListHeap_itemHeap->add(0, b1);
	ListHeap_itemHeap->add(1, b3);
	ListHeap_itemHeap->add(2, b2);
	ListHeap_itemHeap->add(0, b2);

	ListHeap_itemHeap->removeByIndex(4);

	for (int i = 0; i < ListHeap_itemHeap->length(); i++) {
		std::cout << (*(ListHeap_itemHeap->get(i))).k << std::endl;
	}

	// test case 3

	std::cout << "#### test case 3 ####" << std::endl;

	MockClass k1(4);
	MockClass k2(6);
	MockClass k3(5);


	ListStack_itemStack.add(k1);
	ListStack_itemStack.add(k2);
	ListStack_itemStack.add(k3);

	for (int i = 0; i < ListStack_itemStack.length(); i++) {
		std::cout << ListStack_itemStack.get(i).k << std::endl;
	}

	// test case 4

	std::cout << "#### test case 4 ####" << std::endl;

	MockClass k4(4);
	MockClass k5(6);
	MockClass k6(5);

	ListHeap_itemStack->add(k4);
	ListHeap_itemStack->add(k5);
	ListHeap_itemStack->add(k6);

	for (int i = 0; i < ListHeap_itemStack->length(); i++) {
		std::cout << ListHeap_itemStack->get(i).k << std::endl;
	}

	// test case 5 ���� �����ڸ� �̿��� ���� ���� �׽�Ʈ

	std::cout << "#### test case 5 ####" << std::endl;

	// ListStack_itemInt���� 4�� ������ copyThat���� �������� ���� (���� ����)
	ArrayList<int> copyThat(ListStack_itemInt);

	if (ListStack_itemInt.remove(4)) {
		for (int i = 0; i < copyThat.length(); i++) {
			std::cout << copyThat.get(i) << std::endl;
		}
	}

	for (int i = 0; i < ListStack_itemInt.length(); i++) {
		std::cout << ListStack_itemInt.get(i) << std::endl;
	}


}