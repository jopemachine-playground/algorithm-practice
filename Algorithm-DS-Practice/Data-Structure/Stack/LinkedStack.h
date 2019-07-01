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

	// ���� ���縦 �Ϸ���, head���� �����ؼ� ����Ʈ�� ���� �ٽ� ������ �� �� ��
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

	// ������ ���ҿ� ������ ��带 �������
	void insert(T data) {

		// ����Ʈ�� ù ���Ұ� ���� ���
		if (head->next == nullptr) {
			Node* newNode = new Node(nullptr, data);
			head->next = newNode;
			tail = newNode;
			count++;
			return;
		}

		// ����Ʈ�� ���Ұ� �ִ� ���
		Node* newNode = new Node(nullptr, data);
		tail->next = newNode;
		tail = newNode;
		count++;
	};

	// �ε����� ������ ��带 �������
	void insert(int index, T data) {

		if (index > count + 1) {
			throw std::out_of_range("out of range");
			return;
		}

		Node* iterator = head;

		// ����Ʈ�� ù ���Ұ� ���� ���
		if (head->next == nullptr) {
			Node* newNode = new Node(nullptr, data);
			head->next = newNode;
			tail = newNode;
			count++;
			return;
		}

		// ����Ʈ�� ���Ұ� �ִ� ���
		for (int i = 0; i < index - 1; i++) {
			iterator = iterator->next;
		}

		Node* newNode = new Node(iterator->next, data);

		// �����ϴ� ���Ұ� ������ �ε����� ���
		if (iterator->next == nullptr) {
			tail = newNode;
		}

		iterator->next = newNode;

		count++;
	};

	void remove(T target) {

		// ������ ��尡 ó�� ����� ���
		if (head->next->data == target) {

			Node* target = head->next;

			head->next = head->next->next;

			delete target;

			count--;

			return;
		}

		// ������ ��尡 ó�� ��尡 �ƴ϶�� �ݺ����� ���� ��ȸ
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

	// ���� ���
	Node* head = new Node();
	Node* tail = new Node();

	std::unique_ptr<Allocator> allocator;

	int count;

};

void LinkedStack_test() {

	std::unique_ptr<LinkedStack<int>> linkedStack = std::make_unique<LinkedStack<int>>();



}