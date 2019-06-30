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

		// targetIndex가 count / 2 를 초과하는 경우, tail에서, 미만인 경우 head에서 접근한다.
		if (targetIndex > count / 2) {

			iterator = tail;

			// 인덱스가 0에서 시작하므로 1을 빼야 한다는 점에 유의할 것
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

	// 마지막 원소에 데이터 노드를 집어넣음
	const void insert(const T data) {

		// 리스트에 첫 원소가 들어가는 경우
		if (head->next == nullptr) {
			Node* newNode = new Node(head, nullptr, data);
			head->next = newNode;
			head->prev = newNode;
			tail = newNode;
			count++;
			return;
		}

		// 리스트에 원소가 있는 경우
		Node* newNode = new Node(tail, nullptr, data);
		tail->next = newNode;
		tail = newNode;
		head->prev = tail;
		tail->next = head->next;
		count++;
	};

	// 인덱스에 데이터 노드를 집어넣음
	const void insert(const int index, const T data) {

		if (index > count + 1) {
			throw std::out_of_range("out of range");
			return;
		}

		Node* iterator = head;

		// 리스트에 첫 원소가 들어가는 경우
		if (head->next == nullptr) {
			Node* newNode = new Node(head, nullptr, data);
			head->next = newNode;
			head->prev = newNode;
			tail = newNode;
			count++;
			return;
		}

		// 리스트에 원소가 있는 경우
		for (int i = 0; i < index - 1; i++) {
			iterator = iterator->next;
		}

		Node* newNode = new Node(iterator, iterator->next, data);

		// 새로 만든 노드가 마지막 노드이면 tail을 갱신
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

		// 삭제할 노드가 처음 노드인 경우
		if (head->next->data == target) {

			Node* target = head->next;

			head->next = head->next->next;

			delete target;

			tail->next = head->next->next;

			head->next->next->prev = tail;

			count--;

			return;
		}

		// 삭제할 노드가 처음 노드가 아니라면 반복문을 돌며 순회
		Node* iterator;

		for (iterator = head; true; iterator = iterator->next) {

			if (iterator->next->data == target) {

				Node* target = iterator->next;

				iterator->next = iterator->next->next;

				iterator->next->prev = iterator;

				// 삭제할 노드가 마지막 노드이면 tail을 갱신
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

		// targetIndex가 count / 2 를 초과하는 경우, tail에서, 미만인 경우 head에서 접근한다.
		if (targetIndex > count / 2) {

			iterator = tail;

			// 인덱스가 0에서 시작하므로 1을 빼야 한다는 점에 유의할 것
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
		
		// 삭제할 노드가 마지막 노드이면 tail을 갱신
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

	// head는 더미 노드이지만, tail은 마지막에 삽입된 실제 노드를 가리킴에 주의.
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