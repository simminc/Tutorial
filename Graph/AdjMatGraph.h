#include<iostream>
#include<vector>
#include<queue>

#define MAX_VTX 256
#define INF 9999

using namespace std;

class AdjMatGraph {
protected:
	int size; // 정점개수
	char vertices[MAX_VTX];
	bool visited[MAX_VTX];
	int adjMatrix[MAX_VTX][MAX_VTX];
	int label[MAX_VTX];
	int dist[MAX_VTX];
	bool found[MAX_VTX];
	int FloydPath[MAX_VTX][MAX_VTX];
public :
	AdjMatGraph() { reset(); }
	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adjMatrix[i][j]; }
	void setEdge(int i, int j, int val) { adjMatrix[i][j] = val; }

	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_VTX; }
	bool isLinked(int firstVertex, int secondVertex) { return getEdge(firstVertex, secondVertex) != 0; }
	void reset() {
		size = 0;
		resetVisited();
		for (int i = 0; i < MAX_VTX; i++) {
			for (int j = 0; j < MAX_VTX; j++) {
				setEdge(i, j, 0);
			}
		}
	}

	void resetVisited() {
		for (int i = 0; i < MAX_VTX; i++) {
			visited[i] = false;
		}
	}

	void insertVertex(char name) {
		if (!isFull()) {
			vertices[size++] = name;
		}
		else {
			cout << "정점개수 초과" << endl;
		}
	}

	void insertEdge(int u, int v,int val) {
		setEdge(u, v, val);
		setEdge(v, u, val); // 무방향 일때만
	}

	void display() {
		cout << "정점의 갯수 : " << size <<endl;
		for (int i = 0; i < size; i++) {
			cout << getVertex(i) << "        ";
			for (int j = 0; j < size; j++) {
				cout << getEdge(i, j) << " ";
			}
			cout << endl;
		}
	}

	void load(char* filename) {
		FILE *fp = fopen(filename, "r");
		if (fp != NULL) {
			int n, val;
			fscanf(fp, "%d", &n);
			for (int i = 0; i < n; i++) {
				char str[80];
				fscanf(fp, "%s", str);
				insertVertex(str[0]);

				for (int j = 0; j < n; j++) {
					int val;
					fscanf(fp, "%d", &val);
					if (val != 0) {
						insertEdge(i, j, val);
					}
				}
			}
			fclose(fp);
		}
	}

	void DFS(int v) {
		visited[v] = true;
		cout << vertices[v] << " -> ";

		for (int i = 0; i < size; i++) {
			if (isLinked(v, i) && visited[i] != true) {
				DFS(i);
			}
		}
	}

	void BFS(int v) {
		resetVisited();
		visited[v] = true;
		cout << getVertex(v) << " -> " ;

		queue<int> queueForBFS;
		queueForBFS.push(v);

		while (!queueForBFS.empty()) {
			int v = queueForBFS.front();
			queueForBFS.pop();

			for (int i = 0; i < size; i++) {
				if (isLinked(v, i) && visited[i] != true) {
					visited[i] = true;
					cout << getVertex(i) << " -> ";
					queueForBFS.push(i);
				}
			}
		}
	}

	void labelDFS(int v,int color) {
		visited[v] = true;
		label[v] = color;
		for (int i = 0; i < size; i++) {
			if (isLinked(v, i) && visited[i] == false) {
				labelDFS(i, color);
			}
		}
	}

	void findConnectedComponent() {
		resetVisited();
		int count = 0;

		for (int i = 0; i < size; i++) { // count ==> 색
			if (visited[i] == false) {
				labelDFS(i, count);
				count++;
			}
		}

		cout << endl;
		for(int i = 0; i < size; i++) {
			cout << getVertex(i) << "=>" << label[i] << endl;
		}
	}

	int chooseVertex() {
		int min = INF;
		int minpos = -1;

		for (int i = 0; i < size; i++) {
			if (dist[i] < min && !found[i]) {
				min = dist[i];
				minpos = i;
			}
		}
		return minpos;
	}

	void ShortestPath(int start) {
		for (int i = 0; i < size; i++) {
			dist[i] = getEdge(start, i);
			found[i] = false;
		}

		found[start] = true;
		dist[start] = 0;

		for (int i = 0; i < size; i++) {
			cout << "Step[" << i + 1 << "] : ";
			printDistance();

			int u = chooseVertex();
			found[u] = true;

			for (int w = 0; w < size; w++) {
				if (found[w] == false) {
					if (dist[u] + getEdge(u, w) < dist[w]) {
						dist[w] = dist[u] + getEdge(u, w);
					}
				}
			}
		}
	}

	void printDistance() {
		for (int i = 0; i < size; i++) {
			cout << dist[i] << " ";
		}
		cout << endl;
	}

	void ShortestPathFloyd() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				FloydPath[i][j] = getEdge(i, j);
			}
		}

		for (int k = 0; k < size; k++) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (FloydPath[i][k] + FloydPath[k][j] < FloydPath[i][j]) {
						FloydPath[i][j] = FloydPath[i][k] + FloydPath[k][j];
					}
				}
			}
			printFloyd();
		}
	}

	void printFloyd() {
		cout << "============================" << endl;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (FloydPath[i][j] == INF) {
					cout << "INF";
				}
				else {
					cout << FloydPath[i][j] << "  ";
				}
				
			}
			cout << endl;
		}
	}
};