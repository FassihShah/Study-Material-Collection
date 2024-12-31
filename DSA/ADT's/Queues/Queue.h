#ifndef QUEUE_H
#define QUEUE_H
template<typename T>
class Queue
{
	T* queue;
	int size;
	int rear;
	int frnt;
public:
	Queue(int);
	void enQueue(T);
	T deQueue();
	T front();
	bool isFull();
	bool isEmpty();
	int getSize();
};
template class Queue<int>;
#endif