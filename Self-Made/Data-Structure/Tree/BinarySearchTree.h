#pragma once

#include <iostream>
#include <memory>

// T는 당연히 크기 별로 정렬할 수 있는 객체여야 한다 ( 크기비교 operator 를 재정의 해야한다 )
// BinarySearchTree은 중복을 허용하지 않는다
template<class T, class Allocator = std::lloacator<T>>
class BinarySearchTree {
public:

	BinarySearchTree() : count(0) {

	}

	BinarySearchTree(T item) : count(0) {
		root->item = item;
		count++;
	}

	BinarySearchTree(BinarySearchTree& rhs) {
	}

	const void add(const T item) {
		// 처음 트리를 만들 때
		if (root->item == NULL) {
			root->item = item;
			return;
		}

		// 삽입하는 경우
		add_recursive(item, root);
	}

	const void remove(const T item) {
		if (root->item == NULL) {
			return;
		}

		remove_recursive(item, root, root);
	}

	~BinarySearchTree() {
	}


	void clear() {
		count = 0;
	};

	bool isEmpty() {
		return count == 0;
	};

	const int length() const {
		return count;
	};

	const void printAscending() const {
		inorderPrint(root);
	}

private:

	class Node {
	public:
		T item;
		Node* leftChild;
		Node* rightChild;
		Node() : item(NULL), leftChild(nullptr), rightChild(nullptr) {};
		Node(T item) : item(item), leftChild(nullptr), rightChild(nullptr) {};
		Node(T item, Node* left, Node* right) : item(item), leftChild(left), rightChild(right) {}
	};

	Allocator* allocator = new Allocator();

	Node* root = new Node();

	int count;

	const void inorderPrint(Node* subtree) const {
		if (subtree == nullptr) {
			return;
		}
		inorderPrint(subtree->leftChild);

		if (subtree->leftChild != nullptr && subtree->rightChild != nullptr) {
			std::cout << "Item: " << subtree->item << ", left: " << subtree->leftChild->item << ", : right: " << subtree->rightChild->item << std::endl;
		}
		else if (subtree->leftChild == nullptr && subtree->rightChild != nullptr) {
			std::cout << "Item: " << subtree->item << ", left: null, right: " << subtree->rightChild->item << std::endl;
		}
		else if (subtree->leftChild != nullptr && subtree->rightChild == nullptr) {
			std::cout << "Item: " << subtree->item << ", left: " << subtree->leftChild->item << ", : right: null" << std::endl;
		}
		else {
			std::cout << "Item: " << subtree->item << ", left: null, right: null"<< std::endl;
		}

		inorderPrint(subtree->rightChild);
	}

	const void deleteNode(const T target, Node* deleteNode, Node* predecessor) {

		Node* successor = nullptr;
		Node* iterator;

		// 삭제하려는 노드의 왼쪽 자식이 존재할 경우 후속자를 왼쪽 노드들 중 결정해야함
		if (deleteNode->leftChild != nullptr) {

			iterator = deleteNode->leftChild;

			while (true) {

				// 후속자가 바로 아래의 노드인 경우
				if (deleteNode->leftChild->rightChild == nullptr) {
					successor = deleteNode->leftChild;
					break;
				}

				if (iterator->rightChild != nullptr) {

					successor = iterator->rightChild;
					// 후속자 노드에 오른쪽 자식 노드가 있는 경우
					if (iterator->rightChild->rightChild == nullptr && iterator->rightChild->rightChild != nullptr) {
						iterator->rightChild = iterator->leftChild->rightChild;
						break;
					}
					// 후속자 노드에 오른쪽 자식 노드가 없는 경우
					else if (iterator->rightChild->rightChild == nullptr && iterator->rightChild->rightChild == nullptr) {
						iterator->rightChild = nullptr;
						break;
					}

				}

				iterator = iterator->rightChild;
			}


			if (target < predecessor->item && deleteNode != predecessor) {
				predecessor->leftChild = successor;
			}
			else if (target > predecessor->item && deleteNode != predecessor){
				predecessor->rightChild = successor;
			}
			// 루트 노드를 삭제한 경우
			else if (deleteNode == predecessor) {
				root = successor;
			}
			else {
				std::cout << "Error Occur in deleteNode" << std::endl;
			}

			// 후속자가 바로 밑의 노드인 경우
			if (deleteNode->leftChild == successor) {
				successor->rightChild = deleteNode->rightChild;
			}
			else {
				successor->leftChild = deleteNode->leftChild;
				successor->rightChild = deleteNode->rightChild;
			}

		}
		// 삭제하려는 노드의 오른쪽 자식만 존재할 경우 후속자를 오른쪽 노드들 중 결정해야함
		else if (deleteNode->rightChild != nullptr) {

			iterator = deleteNode->rightChild;

			while (true) {

				// 후속자가 바로 아래의 노드인 경우
				if (deleteNode->rightChild->leftChild == nullptr) {
					successor = deleteNode->rightChild;
					break;
				}

				if (iterator->leftChild != nullptr) {

					successor = iterator->leftChild;

					// 후속자 노드에 오른쪽 자식 노드가 있는 경우
					if (iterator->leftChild->leftChild == nullptr && iterator->leftChild->rightChild != nullptr) {
						iterator->leftChild = iterator->leftChild->rightChild;
						break;
					}
					// 후속자 노드에 오른쪽 자식 노드가 없는 경우
					else if (iterator->leftChild->leftChild == nullptr && iterator->leftChild->rightChild == nullptr) {
						iterator->leftChild = nullptr;
						break;
					}

				}

				iterator = iterator->leftChild;
			}

			if (target < predecessor->item && deleteNode != predecessor) {
				predecessor->leftChild = successor;
			}
			else if(target > predecessor->item && deleteNode != predecessor) {
				predecessor->rightChild = successor;
			}
			// 루트 노드를 삭제한 경우
			else if (deleteNode == predecessor) {
				root = successor;
			}
			else {
				std::cout << "Error Occur in deleteNode" << std::endl;
			}

			// 후속자가 바로 밑의 노드인 경우
			if (deleteNode->rightChild == successor) {
				
			}
			else {
				successor->leftChild = deleteNode->leftChild;
				successor->rightChild = deleteNode->rightChild;
			}
		}
		// 삭제하려는 노드의 자식이 없다면 predecessor의 해당 자식을 nullptr로 만들어야 한다.
		else {
			if (target < predecessor->item) {
				predecessor->leftChild = nullptr;
			}
			else if (target > predecessor->item) {
				predecessor->rightChild = nullptr;
			}
		}

		delete deleteNode;
		deleteNode = nullptr;
		count--;
		return;
	}

	const void remove_recursive(const T target, Node* subtree, Node* predecessor) {

		// 삭제할 노드를 발견하면 삭제한다
		if (target == subtree->item) {
			deleteNode(target, subtree, predecessor);
			return;
		}

		// 삭제하려는 노드가 아닌 경우 트리를 탐색하며 삭제할 노드를 찾는다
		if (target > subtree->item) {
			if (subtree->rightChild == nullptr) {
				return;
			}
			remove_recursive(target, subtree->rightChild, subtree);
		}
		else if (target < subtree->item) {
			if (subtree->leftChild == nullptr) {
				return;
			}
			remove_recursive(target, subtree->leftChild, subtree);
		}
	}

	const void add_recursive(const T target, Node* subtree) {

		if (target > subtree->item) {

			// 리프에 도달하면 재귀를 끝냄
			if (subtree->rightChild == nullptr) {
				Node* newNode = new Node(target);
				subtree->rightChild = newNode;
				count++;
				return;
			}

			add_recursive(target, subtree->rightChild);
		}
		else if (target < subtree->item) {

			if (subtree->leftChild == nullptr) {
				Node* newNode = new Node(target);
				subtree->leftChild = newNode;
				count++;
				return;
			}

			add_recursive(target, subtree->leftChild);
		}
	}

};

void BinarySearchTree_test() {

	BinarySearchTree<int>* tree = new BinarySearchTree<int>();

	tree->add(100);
	tree->add(67);
	tree->add(7);
	tree->add(87);
	tree->add(97);
	tree->add(110);
	tree->add(103);
	tree->add(76);
	tree->add(2);
	tree->add(9);
	tree->add(1);
	tree->add(6);
	tree->add(722);
	tree->add(887);
	tree->add(9157);
	tree->add(1101);
	tree->add(112);
	tree->add(761);
	tree->add(22);
	tree->add(95);

	std::cout << tree->length() << std::endl;

	tree->remove(67);
	tree->remove(9);
	tree->remove(110);
	tree->remove(100);
	tree->remove(2);
	tree->remove(7);
	tree->remove(97);
	tree->remove(87);
	tree->remove(103);

	std::cout << tree->length() << std::endl;

	tree->printAscending();
}
