#pragma once
#include <memory>
#include <iostream>
#include "../MockClass.h"

template<class T, class Allocator = std::allocator<T>>
class DoubleLinkedList {
public:

	DoubleLinkedList(): count(0) {}

	DoubleLinkedList(const DoubleLinkedList& rhs): count(0) {
		for (int i = 0; i < rhs.count; i++) {
			this->insert(rhs.get(i));
		}
	};

	~DoubleLinkedList() {
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
	};

	const T get(const int targetIndex) const {

		if (targetIndex > count + 1) {
			throw std::out_of_range("");
			return NULL;
		}

		Node* iterator;

		// targetIndex�� count / 2 �� �ʰ��ϴ� ���, tail����, �̸��� ��� head���� �����Ѵ�.
		if (targetIndex > count / 2) {

			iterator = tail;

			// �ε����� 0���� �����ϹǷ� 1�� ���� �Ѵٴ� ���� ������ ��
			for (int i = 0; i < count - targetIndex - 1; i++) {
				iterator = iterator->prev;
			}

		}
		else {

			iterator = head->next;

			for (int i = 0; i < targetIndex; i++) {
				iterator = iterator->next;
			}
		
		}
		return iterator->data;
	};

	// ������ ���ҿ� ������ ��带 �������
	const void insert(const T data) {

		// ����Ʈ�� ù ���Ұ� ���� ���
		if (head->next == nullptr) {
			Node* newNode = new Node(head, nullptr, data);
			head->next = newNode;
			tail = newNode;
			count++;
			return;
		}

		// ����Ʈ�� ���Ұ� �ִ� ���
		Node* newNode = new Node(tail, nullptr, data);
		tail->next = newNode;
		tail = newNode;
		count++;
	};

	// �ε����� ������ ��带 �������
	const void insert(const int index, const T data) {

		if (index > count + 1) {
			throw std::out_of_range("out of range");
			return;
		}

		Node* iterator = head;

		// ����Ʈ�� ù ���Ұ� ���� ���
		if (head->next == nullptr) {
			Node* newNode = new Node(head, nullptr, data);
			head->next = newNode;
			tail = newNode;
			count++;
			return;
		}

		// ����Ʈ�� ���Ұ� �ִ� ���
		for (int i = 0; i < index - 1; i++) {
			iterator = iterator->next;
		}

		Node* newNode = new Node(iterator, iterator->next, data);

		// ���� ���� ��尡 ������ ����̸� tail�� ����
		if (iterator->next == nullptr) {
			iterator->next = newNode;
			tail = newNode;
		}
		else {
			iterator->next->prev = newNode;
			iterator->next = newNode;
		}

		count++;
	};

	const void remove(const T target) {

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

	const void removeByIndex(const int targetIndex) {

		if (targetIndex > count - 1) {
			throw std::out_of_range("out of range");
			return;
		}

		Node* iterator;

		// targetIndex�� count / 2 �� �ʰ��ϴ� ���, tail����, �̸��� ��� head���� �����Ѵ�.
		if (targetIndex > count / 2) {

			iterator = tail;

			// �ε����� 0���� �����ϹǷ� 1�� ���� �Ѵٴ� ���� ������ ��
			for (int i = 0; i < count - targetIndex - 1; i++) {
				iterator = iterator->prev;
			}
		}
		else {

			iterator = head->next;

			for (int i = 0; i < targetIndex; i++) {
				iterator = iterator->next;
			}
		}

		Node* temp = iterator;

		iterator = iterator->next;

		delete temp;

		count--;
	};

	const int length() const{
		return count;
	};

private:

	class Node {
	public:
		Node* next;
		Node* prev;
		T data;

		Node() {
			next = nullptr;
			prev = nullptr;
			data = NULL;
		};

		Node(Node* _prev, Node* _next , T _data) {
			prev = _prev;
			next = _next;
			data = _data;
		};
	};

	// head�� ���� ���������, tail�� �������� ���Ե� ���� ��带 ����Ŵ�� ����.
	Node* head = new Node();
	Node* tail = new Node();

	std::unique_ptr<Allocator> allocator;

	int count;

};

void DoubleLinkedList_test() {

	DoubleLinkedList<int>* linkedList = new DoubleLinkedList<int>();

	DoubleLinkedList<int> copyTest(*linkedList);

	linkedList->insert(0, 1);
	linkedList->insert(0, 3);
	linkedList->insert(0, 2);

	linkedList->removeByIndex(2);
	linkedList->removeByIndex(1);

	for (int i = 0; i < linkedList->length(); i++) {
		std::cout << linkedList->get(i) << std::endl;
	}


}