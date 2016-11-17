#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include"AdjMatGraph.h"
using namespace std;

void main() {
	AdjMatGraph g;

	/*for (int i = 0; i < 4; i++) {
		g.insertVertex('A' + i);
	}
	g.insertEdge(0, 1);
	g.insertEdge(0, 3);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 3);*/

	g.load("input2.txt");
	/*
	cout << "-----------------------" << endl;
	g.display();
	cout << "-----------------------" << endl;
	g.DFS(0);
	cout << endl;
	cout << "-----------------------" << endl;
	g.BFS(0);

	g.findConnectedComponent();
	*/
	//g.ShortestPath(0);
	g.ShortestPathFloyd();
}