#include"HeapNode.h"
#include<vector>
class MaxHeap {
	vector<HeapNode> node;
	int size;
public :
	MaxHeap() { size = 0; node.reserve(100); node.push_back(-1); }

	bool IsEmpty() {
		return size == 0;
	}

	HeapNode getParent(int i) { return node[i / 2]; }
	HeapNode getLeft(int i) { return node[i * 2]; }
	HeapNode getRight(int i) { return node[i * 2 + 1]; }
	
	void insert(int key) {
		int i = ++size;
		node.push_back(NULL);

		while (i != 1 && key > getParent(i).GetKey()) {
			node[i] = getParent(i);
			i = i / 2;
		}
		node[i].SetKey(key);
	};

	HeapNode remove() {
		if (IsEmpty()) return NULL;

		HeapNode item = node[1];
		HeapNode last = node[size--];

		int parent = 1;
		int child = 2;

		while (child <= size) {
			if (child < size && getLeft(parent).GetKey() < getRight(parent).GetKey())
				child++;

			if (last.GetKey() >= node[child].GetKey()) break;

			node[parent] = node[child];
			parent = child;
			child *= 2;
		}

		node[parent] = last;

		return item;
	};

	vector<int> HeapSort(vector<int> input) {
		MaxHeap h;
		vector<int> result;
		result.reserve(input.size());
		for (int i = 0; i < input.size(); i++) {
			h.insert(input[i]);
		}
		for (int i = 0; i < input.size(); i++) {
			result.push_back(h.remove().GetKey());
		}
		return result;
	}

	void display() {
		for (int i = 1, level = 1; i <= size; i++) {
			if (i == level) {
				cout << endl;
				level *= 2;
			}
			node[i].display();
		}

		cout << endl;
		cout << "------------------" << endl;
	}
};