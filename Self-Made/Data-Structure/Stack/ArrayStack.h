#pragma once
#include <iostream>
#include <memory>

const int ArrayStack_Default_MAX = 1;

template<class T, class Allocator = std::allocator<T>>
class ArrayStack {
public:

	ArrayStack() {
		count = 0;
		capacity = ArrayStack_Default_MAX;
		arrayStack = allocator->allocate(capacity);
	}

	ArrayStack(int initial_Max) : capacity(initial_Max) {
		count = 0;
		arrayStack = allocator->allocate(capacity);
	}

	ArrayStack(ArrayStack& rhs) {
		count = rhs.count;
		capacity = rhs.capacity;
		arrayStack = allocator->allocate(capacity);

		for (int i = 0; i < count; i++) {
			arrayStack[i] = rhs.arrayStack[i];
		}
	}

	~ArrayStack() {
		delete arrayStack;
		arrayStack = nullptr;
	}

	T pop() {
		return arrayStack[--count];
	};

	T peek() {
		return arrayStack[count - 1];
	};

	void push(T item) {
		if (count + 1 > capacity) {
			resize();
		}
		arrayStack[count++] = item;
	};

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

	Allocator* allocator = new Allocator();

	int count;

	int capacity;

	T* arrayStack;

	void resize() {
		capacity *= 2;
		T * newArrayStack = allocator->allocate(capacity);
		for (int i = 0; i < count; i++) {
			newArrayStack[i] = arrayStack[i];
		}
		delete arrayStack;
		arrayStack = newArrayStack;
	}

};

void ArrayStack_test() {

	ArrayStack<int>* stack = new ArrayStack<int>();

	stack->push(1);
	stack->push(3);
	stack->push(2);
	stack->push(5);
	stack->push(7);

	//stack->pop();

	int length = stack->length();

	for (int i = 0; i < length; i++) {
		std::cout << stack->pop() << std::endl;
	}

	stack->push(2);
	stack->push(4);
	stack->push(6);
	stack->push(8);
	stack->push(10);

	int length2 = stack->length();

	for (int i = 0; i < length2; i++) {
		std::cout << stack->pop() << std::endl;
	}

	stack->clear();

}
