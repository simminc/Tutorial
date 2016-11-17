#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include"CustomGraph.h"
using namespace std;

#define MAX_VTX 2000


struct EdgeData {
	int firstVertex;
	int secondVertex;
	EdgeData(int f, int s) {
		firstVertex = f;
		secondVertex = s;
	}
};

struct InputData {
	int verticesCount;
	int edgeCount;
	int startVertex;

	vector<EdgeData> edgeInfo;
};

InputData input() { // ют╥б 
	InputData inputData;

	string input1;
	string input1Parse;
	string input2Parse;
	vector<string> input1Result;

	string input2;

	getline(cin, input1);

	stringstream inputStream(input1);


	while (getline(inputStream, input1Parse, ' ')) {
		input1Result.push_back(input1Parse);
	}
	inputData.verticesCount = stoi(input1Result[0]);
	inputData.edgeCount = stoi(input1Result[1]);
	inputData.startVertex = stoi(input1Result[2]);


	for (int i = 0; i < inputData.edgeCount; i++) {
		getline(cin, input2);
		vector<int> lineData;

		stringstream inputStream2(input2);
		while (getline(inputStream2, input2Parse, ' ')) {

			lineData.push_back(stoi(input2Parse));
		}
		inputData.edgeInfo.push_back(EdgeData(lineData[0], lineData[1]));
	}


	return inputData;
}

void main() {
	InputData inputData;

	inputData = input();

	CustomGraph	g;

	for (int i = 0; i < inputData.verticesCount; i++) {
		g.insertVertex(i + 1);
	}

	for (int i = 0; i < inputData.edgeInfo.size(); i++) {
		g.insertEdge(inputData.edgeInfo[i].firstVertex - 1, inputData.edgeInfo[i].secondVertex - 1);
	}

	g.DFS(0);
	g.BFS(0);

	g.printDFS();
	g.printBFS();

}

