#pragma once
#include <memory>
#include <iostream>
#include "../MockClass.h"

template<class T, class Allocator = std::allocator<T>>
class SingleLinkedList {
public:

	SingleLinkedList(): count(0) {}

	SingleLinkedList(const SingleLinkedList& rhs) : count(0) {
		for (int i = 0; i < rhs.count; i++) {
			this->insert(rhs.get(i));
		}
	};

	~SingleLinkedList() {
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
	};

	const T get(const int index) const {
		
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
	const void insert(const T data) {

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
	const void insert(const int index, const T data) {

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
	
	const void remove(T target) {
		
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
				
				// �����Ϸ��� ��尡 ������ ����� ��� tail�� ����
				if (iterator->next == tail) {
					tail = iterator;
				}

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

		Node* iterator = head;

		for (int i = 0; i < targetIndex; i++) {
			iterator = iterator->next;
		}

		// �����Ϸ��� ��尡 ������ ����� ��� tail�� ����
		if (targetIndex == count - 1) {
			tail = iterator;
		}
		
		Node* temp = iterator->next;

		iterator->next = iterator->next->next;

		delete temp;

		count--;
	};

	const int length() const {
		return count;
	};

private:

	class Node{
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

void SingleLinkedList_test() {

	std::unique_ptr<SingleLinkedList<int>> linkedList = std::make_unique<SingleLinkedList<int>>();

	linkedList->insert(0, 1);
	linkedList->insert(10);
	linkedList->insert(11);

	SingleLinkedList<int> copyTest(*(linkedList).get());

	linkedList->removeByIndex(2);
	linkedList->removeByIndex(1);

	linkedList->remove(11);
	linkedList->remove(10);

	for (int i = 0; i < linkedList->length(); i++) {
		std::cout << linkedList->get(i) << std::endl;
	}

	for (int i = 0; i < copyTest.length(); i++) {
		std::cout << copyTest.get(i) << std::endl;
	}

}