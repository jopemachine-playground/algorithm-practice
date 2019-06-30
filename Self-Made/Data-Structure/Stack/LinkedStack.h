#pragma once
#include <memory>
#include <iostream>
#include "../MockClass.h"

template<class T, class Allocator = std::allocator<T>>
class LinkedStack {
public:

	LinkedStack() {
		count = 0;
	}

	// 깊은 복사를 하려면, head에서 시작해서 리스트를 전부 다시 만들어야 할 듯 함
	LinkedStack(const LinkedStack& linkedList) {
		this.count = linkedList.count;
		this.head = linkedList.head;
		this.tail = linkedList.tail;
	};

	~LinkedStack() {
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
	};

	T get(int index) {

		if (index > count + 1) {
			throw std::out_of_range("");
			return NULL;
		}

		Node* iterator = head->next;

		for (int i = 0; i < index; i++) {
			iterator = iterator->next;
		}

		return iterator->data;
	};

	// 마지막 원소에 데이터 노드를 집어넣음
	void insert(T data) {

		// 리스트에 첫 원소가 들어가는 경우
		if (head->next == nullptr) {
			Node* newNode = new Node(nullptr, data);
			head->next = newNode;
			tail = newNode;
			count++;
			return;
		}

		// 리스트에 원소가 있는 경우
		Node* newNode = new Node(nullptr, data);
		tail->next = newNode;
		tail = newNode;
		count++;
	};

	// 인덱스에 데이터 노드를 집어넣음
	void insert(int index, T data) {

		if (index > count + 1) {
			throw std::out_of_range("out of range");
			return;
		}

		Node* iterator = head;

		// 리스트에 첫 원소가 들어가는 경우
		if (head->next == nullptr) {
			Node* newNode = new Node(nullptr, data);
			head->next = newNode;
			tail = newNode;
			count++;
			return;
		}

		// 리스트에 원소가 있는 경우
		for (int i = 0; i < index - 1; i++) {
			iterator = iterator->next;
		}

		Node* newNode = new Node(iterator->next, data);

		// 삽입하는 원소가 마지막 인덱스인 경우
		if (iterator->next == nullptr) {
			tail = newNode;
		}

		iterator->next = newNode;

		count++;
	};

	void remove(T target) {

		// 삭제할 노드가 처음 노드인 경우
		if (head->next->data == target) {

			Node* target = head->next;

			head->next = head->next->next;

			delete target;

			count--;

			return;
		}

		// 삭제할 노드가 처음 노드가 아니라면 반복문을 돌며 순회
		Node* iterator;

		for (iterator = head; iterator->next != nullptr; iterator = iterator->next) {

			if (iterator->next->data == target) {

				Node* target = iterator->next;

				iterator->next = iterator->next->next;

				delete target;

				count--;

				break;
			}
		}
	};

	void removeByIndex(int targetIndex) {

		if (targetIndex > count - 1) {
			throw std::out_of_range("out of range");
			return;
		}

		Node* iterator = head;

		for (int i = 0; i < targetIndex; i++) {
			iterator = iterator->next;
		}

		Node* temp = iterator->next;

		iterator->next = iterator->next->next;

		delete temp;

		count--;
	};

	int length() {
		return count;
	};

private:

	class Node {
	public:
		Node* next;
		T data;

		Node() {
			next = nullptr;
			data = NULL;
		};

		Node(Node* _ptr, T _data) {
			next = _ptr;
			data = _data;
		};
	};

	// 더미 노드
	Node* head = new Node();
	Node* tail = new Node();

	std::unique_ptr<Allocator> allocator;

	int count;

};

void LinkedStack_test() {

	std::unique_ptr<LinkedStack<int>> linkedStack = std::make_unique<LinkedStack<int>>();



}