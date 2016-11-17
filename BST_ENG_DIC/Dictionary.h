#include<iostream>
#include"BinaryTree.h"

using namespace std;
class Dictionary : public BinaryTree {
public :
	void printAllWords() {
		cout << "���� �ܾ��� => " << endl;
		if(!IsEmpty())
			Inorder(_root);
	}

	void SearchWord(string key) {
		BinaryNode* result = Search(key);
		if (result != NULL) {
			cout << "�ܾ� : " << result->word << ", �ǹ� : " << result->meaning << endl;
		}
		else {
			cout << "���� �ܾ� �Դϴ�" << endl;
		}
	}
};