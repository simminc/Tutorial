#include<iostream>
#include"MaxHeap.h"
#include<vector>

using namespace std;

void main() {
	MaxHeap heap;

	heap.insert(1);
	heap.insert(2);
	heap.insert(3);
	heap.insert(4);
	heap.insert(5);
	heap.insert(6);
	heap.insert(7);
	heap.insert(8);
	heap.insert(9);
	heap.remove();
	heap.display();


	cout << "---------------heap sort---------------" << endl;
	vector<int> input;
	vector<int> result;
	result.reserve(10);
	input.reserve(10);
	input.push_back(5);
	input.push_back(3);
	input.push_back(9);
	input.push_back(2);
	input.push_back(1);
	input.push_back(8);
	input.push_back(7);
	input.push_back(6);
	input.push_back(4);
	input.push_back(10);

	result = heap.HeapSort(input);
	for (int i = 0; i < 10; i++) {
		cout << result[i] << ",";
	}
}