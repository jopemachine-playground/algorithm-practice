#pragma once
#include <memory>
#include <iostream>
#include "../MockClass.h"

const int PriorityQueue_Default_MAX = 100;

// 내부 클래스로 넣으면 std::allocator<PriorityQueue_Node<T>>를 적을 수 없어 밖으로 뺐음
template<class T>
class PriorityQueue_Node {
public:
	T item;
	int priority;

	PriorityQueue_Node(int _priority, T _item) : item(_item), priority(_priority) {};
};

template<class T, class Allocator = std::allocator<PriorityQueue_Node<T>>>
class PriorityQueue {
public:

	PriorityQueue() : count(0), capacity(PriorityQueue_Default_MAX) {
		arrayOfHeap = allocator->allocate(capacity);
	};

	PriorityQueue(int initial_Max) : count(0), capacity(initial_Max) {
		arrayOfHeap = allocator->allocate(capacity);
	};

	PriorityQueue(const PriorityQueue<T>& rhs) : count(rhs.count), capacity(rhs.capacity) {
		arrayOfHeap = allocator->allocate(capacity);

		for (int i = 0; i < count; i++) {
			arrayOfHeap[i] = rhs.arrayOfHeap[i];
		}
	};

	~PriorityQueue() {
		delete arrayOfHeap;
		arrayOfHeap = nullptr;
	};

	T dequeue() {
		T target = arrayOfHeap[0].item;
		deque_recursive(0);
		
		count--;

		return target;
	};

	T retrieve() {
		return arrayOfHeap[0].item;
	}

	void enqueue(T item, int priority) {
		arrayOfHeap[count] = *(new PriorityQueue_Node<T>(priority, item));
		int index = count;
		int parentIndex;

		while (index > 0) {

			parentIndex = getParentIndex(index);
			// 부모 노드보다 더 우선순위가 큰 경우 위로 올라가야 한다
			if (arrayOfHeap[index].priority > arrayOfHeap[parentIndex].priority) {
				swap(arrayOfHeap[index], arrayOfHeap[parentIndex]);
				index = parentIndex;
			}
			// 부모 노드가 더 우선순위가 큰 경우 멈춘다
			else {
				break;
			}
		}
		count++;
	};


	bool isEmpty() {
		return count == 0;
	};

	int length() {
		return count;
	};

	void printArray() {
		for (int i = 0; i < count; i++) {
			std::cout << arrayOfHeap[i].priority << std::endl;
		}
	}

private:

	void swap(PriorityQueue_Node<T>& a, PriorityQueue_Node<T>& b) {
		PriorityQueue_Node<T> temp = a;
		a = b;
		b = temp;
	}

	void deque_recursive(int index) {

		int leftChildIndex = index * 2 + 1;
		int rightChildIndex = index * 2 + 2;

		if (leftChildIndex > count) {
			return;
		}

		if (arrayOfHeap[leftChildIndex].priority < arrayOfHeap[rightChildIndex].priority) {
			swap(arrayOfHeap[rightChildIndex], arrayOfHeap[index]);
			deque_recursive(rightChildIndex);
		}
		else if (arrayOfHeap[leftChildIndex].priority > arrayOfHeap[rightChildIndex].priority) {
			swap(arrayOfHeap[leftChildIndex], arrayOfHeap[index]);
			deque_recursive(leftChildIndex);
		}
	}

	const int getParentIndex(const int childIndex) const {
		if (childIndex <= 0) {
			return 0;
		}

		// index가 짝수일 때
		if (childIndex % 2 == 0) {
			return (childIndex / 2) - 1;
		}
		// index가 홀수 일 때
		else {
			return childIndex / 2;
		}
	}

	std::unique_ptr<Allocator> allocator;

	int count;

	int capacity;

	PriorityQueue_Node<T>* arrayOfHeap;
};

void PriorityQueue_test() {

	PriorityQueue<int>* maxHeap = new PriorityQueue<int>();

	maxHeap->enqueue(3, 1);
	maxHeap->enqueue(1, 3);
	maxHeap->enqueue(1, 2);
	maxHeap->enqueue(1, 5);
	maxHeap->enqueue(100, 10);
	maxHeap->enqueue(1, 7);
	maxHeap->enqueue(1, 8);

	std::cout << maxHeap->dequeue() << std::endl;

	maxHeap->dequeue();
	maxHeap->dequeue();
	maxHeap->dequeue();

	maxHeap->enqueue(1, 12);
	maxHeap->printArray();

	/*	PriorityQueue<MockClass>* maxHeap2 = new PriorityQueue<MockClass>();

	maxHeap2->enqueue(*(new MockClass(3)), 1);
	maxHeap2->enqueue(*(new MockClass(3)), 2);
	maxHeap2->enqueue(*(new MockClass(3)), 4);
	maxHeap2->enqueue(*(new MockClass(3)), 3);
	maxHeap2->enqueue(*(new MockClass(3)), 5);
	maxHeap2->printArray();*/

}