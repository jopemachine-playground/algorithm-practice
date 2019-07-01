#pragma once

#include <iostream>
#include <memory>

// T�� �翬�� ũ�� ���� ������ �� �ִ� ��ü���� �Ѵ� ( ũ��� operator �� ������ �ؾ��Ѵ� )
// BinarySearchTree�� �ߺ��� ������� �ʴ´�
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
		// ó�� Ʈ���� ���� ��
		if (root->item == NULL) {
			root->item = item;
			return;
		}

		// �����ϴ� ���
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

		// �����Ϸ��� ����� ���� �ڽ��� ������ ��� �ļ��ڸ� ���� ���� �� �����ؾ���
		if (deleteNode->leftChild != nullptr) {

			iterator = deleteNode->leftChild;

			while (true) {

				// �ļ��ڰ� �ٷ� �Ʒ��� ����� ���
				if (deleteNode->leftChild->rightChild == nullptr) {
					successor = deleteNode->leftChild;
					break;
				}

				if (iterator->rightChild != nullptr) {

					successor = iterator->rightChild;
					// �ļ��� ��忡 ������ �ڽ� ��尡 �ִ� ���
					if (iterator->rightChild->rightChild == nullptr && iterator->rightChild->rightChild != nullptr) {
						iterator->rightChild = iterator->leftChild->rightChild;
						break;
					}
					// �ļ��� ��忡 ������ �ڽ� ��尡 ���� ���
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
			// ��Ʈ ��带 ������ ���
			else if (deleteNode == predecessor) {
				root = successor;
			}
			else {
				std::cout << "Error Occur in deleteNode" << std::endl;
			}

			// �ļ��ڰ� �ٷ� ���� ����� ���
			if (deleteNode->leftChild == successor) {
				successor->rightChild = deleteNode->rightChild;
			}
			else {
				successor->leftChild = deleteNode->leftChild;
				successor->rightChild = deleteNode->rightChild;
			}

		}
		// �����Ϸ��� ����� ������ �ڽĸ� ������ ��� �ļ��ڸ� ������ ���� �� �����ؾ���
		else if (deleteNode->rightChild != nullptr) {

			iterator = deleteNode->rightChild;

			while (true) {

				// �ļ��ڰ� �ٷ� �Ʒ��� ����� ���
				if (deleteNode->rightChild->leftChild == nullptr) {
					successor = deleteNode->rightChild;
					break;
				}

				if (iterator->leftChild != nullptr) {

					successor = iterator->leftChild;

					// �ļ��� ��忡 ������ �ڽ� ��尡 �ִ� ���
					if (iterator->leftChild->leftChild == nullptr && iterator->leftChild->rightChild != nullptr) {
						iterator->leftChild = iterator->leftChild->rightChild;
						break;
					}
					// �ļ��� ��忡 ������ �ڽ� ��尡 ���� ���
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
			// ��Ʈ ��带 ������ ���
			else if (deleteNode == predecessor) {
				root = successor;
			}
			else {
				std::cout << "Error Occur in deleteNode" << std::endl;
			}

			// �ļ��ڰ� �ٷ� ���� ����� ���
			if (deleteNode->rightChild == successor) {
				
			}
			else {
				successor->leftChild = deleteNode->leftChild;
				successor->rightChild = deleteNode->rightChild;
			}
		}
		// �����Ϸ��� ����� �ڽ��� ���ٸ� predecessor�� �ش� �ڽ��� nullptr�� ������ �Ѵ�.
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

		// ������ ��带 �߰��ϸ� �����Ѵ�
		if (target == subtree->item) {
			deleteNode(target, subtree, predecessor);
			return;
		}

		// �����Ϸ��� ��尡 �ƴ� ��� Ʈ���� Ž���ϸ� ������ ��带 ã�´�
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

			// ������ �����ϸ� ��͸� ����
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
