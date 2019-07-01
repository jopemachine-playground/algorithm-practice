#pragma once
#include <memory>
#include <iostream>
#include "../MockClass.h"

template<class T, class Allocator = std::allocator<T>>
class CircularDoubleLinkedList {
public:

	CircularDoubleLinkedList() : count(0) {}

	CircularDoubleLinkedList(const CircularDoubleLinkedList& rhs) : count(0) {
		for (int i = 0; i < rhs.count; i++) {
			this->insert(rhs.get(i));
		}
	};

	~CircularDoubleLinkedList() {
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
	};

	const T get(const int targetIndex) const {

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
			head->prev = newNode;
			tail = newNode;
			count++;
			return;
		}

		// ����Ʈ�� ���Ұ� �ִ� ���
		Node* newNode = new Node(tail, nullptr, data);
		tail->next = newNode;
		tail = newNode;
		head->prev = tail;
		tail->next = head->next;
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
			head->prev = newNode;
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
			tail->next = head->next;
			head->prev = tail;
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

			tail->next = head->next->next;

			head->next->next->prev = tail;

			count--;

			return;
		}

		// ������ ��尡 ó�� ��尡 �ƴ϶�� �ݺ����� ���� ��ȸ
		Node* iterator;

		for (iterator = head; true; iterator = iterator->next) {

			if (iterator->next->data == target) {

				Node* target = iterator->next;

				iterator->next = iterator->next->next;

				iterator->next->prev = iterator;

				// ������ ��尡 ������ ����̸� tail�� ����
				if (iterator->next == head->next) {
					tail = tail->prev;
					head->prev = tail;
					tail->next = head->next;
				}

				delete target;

				count--;

				break;
			}
		}
	};

	const void removeByIndex(const int targetIndex) {

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
		
		// ������ ��尡 ������ ����̸� tail�� ����
		if (iterator->next == head->next) {
			Node* temp = iterator;

			tail = tail->prev;
			tail->next = head->next;
			head->prev = tail;

			tail->prev->next = tail;
			
			delete temp;
			count--;
		}
		else {
			Node* temp = iterator;
			iterator = iterator->next;
			delete temp;
			count--;
		}

	};

	const int length() const {
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

		Node(Node* _prev, Node* _next, T _data) {
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

void CircularDoubleLinkedList_test() {

	CircularDoubleLinkedList<int>* linkedList = new CircularDoubleLinkedList<int>();

	CircularDoubleLinkedList<int> copyTest(*linkedList);

	linkedList->insert(0, 1);
	linkedList->insert(0, 3);
	linkedList->insert(0, 2);
	linkedList->insert(22);
	linkedList->insert(12);
	linkedList->insert(6);

	//linkedList->removeByIndex(1);
	
	//std::cout << linkedList->get(5) << std::endl;

	linkedList->remove(22);
	linkedList->remove(6);
	std::cout << "ss";
	linkedList->removeByIndex(3);
	
	for (int i = 0; i < linkedList->length(); i++) {
		std::cout << linkedList->get(i) << std::endl;
	}


}