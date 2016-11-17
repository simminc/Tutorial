#include<iostream>
#include<string>
#include"Dictionary.h"
using namespace std;

void help() {
	cout << "���� : i - �߰�, d-����, w-�ܾ�˻�, m-�ǹ̰˻�, p-���, q-����   ==>  " << endl;
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
				cout << "���Դܾ� =>";
				cin >> word;
				cout << "�ܾ� ��=>";
				cin >> meaning;
				tree.Insert(new BinaryNode(word,meaning));
				break;
			case 'd': 
				cout << "�����ܾ� =>";
				cin >> word;
				tree.Remove(word);
				break;
			case 'p': 
				tree.printAllWords();
				cout << endl;
				break;
			case 'w': 
				cout << "�˻��ܾ� =>";
				cin >> word;
				tree.SearchWord(word);
				break;
			case 'm': 
				cout << "�˻��ǹ� =>";
				cin >> word;
				//search meaning
				break;

		}

	} while (command != 'q');
}

