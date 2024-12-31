#ifndef HEAP_TREE_H
#define HEAP_TREE_H
class HeapTree
{
	int* heap;
	int capacity;
	int size;
	void heapifyUp(int index);
	void heapifyDown(int index);
	void reSize();
	void swap(int& a, int& b);
public:
	HeapTree(int cap = 10);
	~HeapTree();
	void insert(int val);
	int deleteMax();
	void display();
};
#endif