#include<iostream>
#include"BinaryTree.h"

using namespace std;
class Dictionary : public BinaryTree {
public :
	void printAllWords() {
		cout << "나의 단어장 => " << endl;
		if(!IsEmpty())
			Inorder(_root);
	}

	void SearchWord(string key) {
		BinaryNode* result = Search(key);
		if (result != NULL) {
			cout << "단어 : " << result->word << ", 의미 : " << result->meaning << endl;
		}
		else {
			cout << "없는 단어 입니다" << endl;
		}
	}
};