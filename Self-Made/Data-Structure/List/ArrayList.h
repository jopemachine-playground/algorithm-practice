#pragma once
#include <memory>
#include <iostream>
#include "../MockClass.h"

const int ArrayList_Default_MAX = 100;

// 템플릿을 사용하기 때문에 헤더파일에 구현을 결합해야 한다.

// https://docs.microsoft.com/ko-kr/cpp/standard-library/allocators?view=vs-2019#writing-your-own-allocator-c11
// 외부에서 들어오는 타입 T의 생성자 정보가 없으므로, Allocator란 클래스를 활용해 객체를 생성해야 한다. 
// 이 클래스는 new 연산자를 쓰지 않고, malloc을 사용해 객체를 생성한다
// 실제로, 아래 template은 Vector 클래스의 템플릿과 동일함

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

	// 이 부분에서 T arrayList[] 가 아니라, 포인터가 와야한다는 게 중요함
	// 내가 한참동안 헷갈렸던 부분이니, 잘 알아두자
	// 힙에 배열을 만들 때, int *array = new int[length]; 라 쓰지 
	// int array[] = new int[length] 라 쓰지 않는다.

	T* arrayList;
};

void ArrayList_test() {

	// 리스트도 리스트 아이템들도 스택에 있는 경우 (또는 프리미티브 타입) (case 1)
	ArrayList<int> ListStack_itemInt(10);

	// 리스트도, 리스트 아이템들도 힙에 있는 경우 (case 2)
	ArrayList<MockClass*>* ListHeap_itemHeap = new ArrayList<MockClass*>(10);

	// 리스트도 스택에, 리스트 아이템들도 스택에 있지만, 아이템들이 객체인 경우 (case 3)
	// case3을 구현하기 위해선, Allocator 클래스를 활용해 ArrayList를 작성해야만 한다.
	// Allocator를 이용해 작성한 클래스는, 따로 T*를 매개로 받는 함수들을 작성할 필요가 없다.
	ArrayList<MockClass> ListStack_itemStack(10);

	// 리스트는 힙에, 리스트 아이템들은 스택에 있는 경우 (case 4)
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

	// test case 5 복사 생성자를 이용한 깊은 복사 테스트

	std::cout << "#### test case 5 ####" << std::endl;

	// ListStack_itemInt에서 4를 지워도 copyThat에선 지워지지 않음 (깊은 복사)
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