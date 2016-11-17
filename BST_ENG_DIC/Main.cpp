#include<iostream>
#include<string>
#include"Dictionary.h"
using namespace std;

void help() {
	cout << "사용법 : i - 추가, d-삭제, w-단어검색, m-의미검색, p-출력, q-종료   ==>  " << endl;
}

void main() {
	char command;

	string word;
	string meaning;

	Dictionary tree;

	do {
		help();

		cin >> command;

		cout << endl;

		switch (command) {
			case 'i': 
				cout << "삽입단어 =>";
				cin >> word;
				cout << "단어 뜻=>";
				cin >> meaning;
				tree.Insert(new BinaryNode(word,meaning));
				break;
			case 'd': 
				cout << "삭제단어 =>";
				cin >> word;
				tree.Remove(word);
				break;
			case 'p': 
				tree.printAllWords();
				cout << endl;
				break;
			case 'w': 
				cout << "검색단어 =>";
				cin >> word;
				tree.SearchWord(word);
				break;
			case 'm': 
				cout << "검색의미 =>";
				cin >> word;
				//search meaning
				break;

		}

	} while (command != 'q');
}

