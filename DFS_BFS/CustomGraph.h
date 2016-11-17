#include<iostream>
#include<queue>

#define MAX_VTX 100

using namespace std;

class CustomGraph {
public :
	int size;
	int vertices[MAX_VTX];
	int adjMaxtrix[MAX_VTX][MAX_VTX];
	bool visited[MAX_VTX];

	vector<int> DFS_result;
	vector<int> BFS_result;

	CustomGraph() { 
		size = 0; 
		for (int i = 0; i < MAX_VTX; i++) {
			visited[i] = 0;
		}

		for (int i = 0; i < MAX_VTX; i++) {
			for (int j = 0; j < MAX_VTX; j++) {
				adjMaxtrix[i][j] = 0;
			}
		}
	}

	void resetVisit() {
		for (int i = 0; i < size; i++) {
			visited[i] = false;
		}
	}

	int getVertex(int i) {
		return vertices[i];
	}
	
	void insertVertex(int v) {
		vertices[size] = v;
		size++;
	}

	void insertEdge(int firstTarget, int secondTarget) {
		if (!isLinked(firstTarget,secondTarget)) {
			adjMaxtrix[firstTarget][secondTarget] = 1;
			adjMaxtrix[secondTarget][firstTarget] = 1;
		}
	}

	bool isLinked(int f, int s) {
		return (adjMaxtrix[f][s] == 1 || adjMaxtrix[s][f] == 1);
	}

	void DFS(int v) {
		DFS_result.push_back(getVertex(v));
		visited[v] = true;

		for (int i = 0; i < size; i++) {
			if (isLinked(v, i) && visited[i] == false) {
				visited[i] = true;
				DFS(i);
			}
		}
	}

	void BFS(int v) {
		resetVisit();

		queue<int> queueForBFS;

		queueForBFS.push(v);
		visited[v] = true;

		while (!queueForBFS.empty()) {
			int front = queueForBFS.front();

			queueForBFS.pop();
			BFS_result.push_back(getVertex(front));
			
			for (int i = 0; i < size; i++) {
				if (isLinked(front, i) && visited[i] == false) {
					queueForBFS.push(i);
					visited[i] = true;
				}
			}
		}
	}

	void printDFS() {
		for (int i = 0; i < DFS_result.size(); i++) {
			cout << DFS_result[i] << " ";
		}
		cout << endl;
	}

	void printBFS() {
		for (int i = 0; i < BFS_result.size(); i++) {
			cout << BFS_result[i] << " ";
		}
	}
};