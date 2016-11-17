#include"BinaryNode.h"

class BinaryTree {
protected:
	BinaryNode* _root;
public :
	BinaryTree() : _root(NULL) {}
	
	bool IsEmpty() { return _root == NULL; }
	
	void Inorder(BinaryNode* node) {
		if (node != NULL) {
			if (node->getLeft() != NULL) { Inorder(node->getLeft()); }
			node->display();

			if (node->getRight() != NULL) { Inorder(node->getRight()); }
		}
	}

	BinaryNode* Search(string key) {
		return SearchRecur(_root,key);
	}

	BinaryNode* SearchRecur(BinaryNode* node, string key) {
		if (node == NULL) {
			return NULL;
		}
		if (node->compare(key) == 0) {
			return node;
		}
		else if (node->compare(key) < 0) {
			SearchRecur(node->getLeft(), key);
		}
		else {
			SearchRecur(node->getRight(), key);
		}
	}

	void Insert(BinaryNode* node) {
		if (node == NULL) {
			return;
		}
		if (IsEmpty()) {
			_root = node;
		}
		else {
			InsertRecursive(_root, node);
		}
	}

	void InsertRecursive(BinaryNode* node, BinaryNode* key) {
		if (node->compare(key->word) < 0) {
			if (node->getLeft() == NULL) {
				node->setLeft(key);
			}
			else {
				InsertRecursive(node->getLeft(), key);
			}
		}
		else {
			if (node->getRight() == NULL) {
				node->setRight(key);
			}
			else {
				InsertRecursive(node->getRight(), key);
			}
		}
	}

	void Remove(string key) {
		if (IsEmpty()) return;
		BinaryNode* parent = NULL;
		BinaryNode* node = _root;

		while (node != NULL && node->compare(key) != 0) { //삭제하려는 노드와 그의 부모노드를 찾는다.
			parent = node;
			node = node->compare(key) < 0 ? node->getLeft() : node->getRight();
		}

		if (node != NULL) {
			Remove(parent, node);
		}
	}

	void Remove(BinaryNode* parent, BinaryNode* node) {
		if (node->isLeaf()) { // 단말노드 삭제
			if (parent == NULL) {
				_root = NULL;
			}
			else {
				if (parent->getLeft() == node) {
					parent->setLeft(NULL);
				}
				else {
					parent->setRight(NULL);
				}
			}
		}
		else if(node->getLeft() == NULL || node->getRight() == NULL){ // 자식이 왼 or 오 만 있는 노드 삭제
			BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();


			if (node == _root) {
				_root = child;
			}
			else {
				if (parent->getLeft() == node) {
					parent->setLeft(child);
				}
				else {
					parent->setRight(child);
				}
			}
		}
		else {
			BinaryNode* succp = node;
			BinaryNode* succ = node->getRight();

			while (succ->getLeft() != NULL) {
				succp = succ;
				succ = succ->getLeft();
			}

			if (succp->getLeft() == succ) {
				succp->setLeft(succ->getRight());
			}
			else {
				succp->setRight(succ->getRight());
			}

			node->word = succ->word;
			node->meaning = succ->meaning;

			node = succ;
		}
		delete node;
	}
};