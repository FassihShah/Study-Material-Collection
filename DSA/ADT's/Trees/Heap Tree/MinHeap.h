#ifndef MIN_HEAP_H
#define MIN_HEAP_H
class MinHeap
{
	int* heap;
	int capacity;
	int size;

	int left(int i);
	int right(int i);
	int parent(int i);
	void heapifyUp(int i);
	void heapifyDown(int i);
	void swap(int& a, int& b);
public:
	MinHeap(int cap);
	~MinHeap();
	void enqueue(int t);
	int dequeue();
	int peek() const;
	bool isEmpty() const;
	int getSize() const;
};
#endif