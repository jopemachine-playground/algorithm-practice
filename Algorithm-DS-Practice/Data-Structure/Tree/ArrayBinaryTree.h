// 완전이진트리의 배열을 사용한 구현
#pragma once
#include <iostream>
#include <memory>

const int ArrayBinaryTree_Default_MAX = 1;

template<class T, class Allocator = std::allocator<T>>
class ArrayBinaryTree {
public:

	ArrayBinaryTree(): count(0), capacity(ArrayStack_Default_MAX) {
		arrayStack = allocator->allocate(capacity);
	}

	ArrayBinaryTree(int initial_Max) : count(0), capacity(initial_Max) {
		arrayStack = allocator->allocate(capacity);
	}

	ArrayBinaryTree(ArrayBinaryTree& rhs) {
		count = rhs.count;
		capacity = rhs.capacity;
		array = allocator->allocate(capacity);

		for (int i = 0; i < count; i++) {
			array[i] = rhs.array[i];
		}
	}

	const void insert(const T item) {
		

	}

	const void remove(const T item) {
	
	}

	~ArrayBinaryTree() {
		delete array;
		array = nullptr;
	}


	void clear() {
		count = 0;
		capacity = ArrayStack_Default_MAX;
		delete arrayStack;
	};

	bool isEmpty() {
		return count == 0;
	};

	int length() {
		return count;
	};

private:

	public class Node{
		T item;
		int leftChildIndex;
		int rightChildIndex;

		Node(T item, int left, int right): item (item), leftChildIndex(left), rightChildIndex(right){}
	};

	Allocator* allocator = new Allocator();

	int count;

	int capacity;

	T* array;

	void resize() {
		capacity *= 2;
		T* newArray = allocator->allocate(capacity);
		for (int i = 0; i < count; i++) {
			newArray[i] = arrayStack[i];
		}
		delete arrayStack;
		array = newArrayStack;
	}

};

void ArrayBinaryTree_test() {

	ArrayBinaryTree<int>* tree = new ArrayBinaryTree<int>();



}
