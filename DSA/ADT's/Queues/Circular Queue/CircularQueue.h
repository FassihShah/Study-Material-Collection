#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H
template<typename T>
class CircularQueue
{
	T* queue;
	int size;
	int rear;
	int frnt;
public:
	CircularQueue(int);
	void enQueue(T);
	T deQueue();
	T front();
	bool isFull();
	bool isEmpty();
	int getSize();
};
template class CircularQueue<int>;
#endif