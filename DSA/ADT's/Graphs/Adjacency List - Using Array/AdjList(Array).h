#ifndef ADJLIST_ARRAY_H
#define ADJLIST_ARRAY_H
#include"Array.h"
class AdjList
{
	bool isDirected;
	int vertices;
	Array<Array<int>> graph;
public:
	AdjList(int v, bool d = false);
	void addEdge(int a, int b);
	void print();
	Array<int> breadthFirstSearch();    // using queue
	Array<int> depthFirstSearch();      // using stack
};
#endif