#include<iostream>

using namespace std;

class HeapNode {
public :
	int Key;

	HeapNode(int key = 0) { Key = key; }

	void SetKey(int key) {
		Key = key;
	}

	int GetKey() {
		return Key;
	}

	void display() {
		cout << Key;
	}
};