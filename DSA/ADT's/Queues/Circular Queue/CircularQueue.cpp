#include<iostream>
#include"CircularQueue.h"
using namespace std;
template<typename T>
CircularQueue<T>::CircularQueue(int s)
{
	size = s;
	queue = new T[size];
	rear = -1;
	frnt = -1;
}
template<typename T>
void CircularQueue<T>::enQueue(T val)
{
	if (isFull())
	{
		cout << "\nQueue is Full!";
		return;
	}
	else
	{
		rear = (rear + 1) % size;
		queue[rear] = val;
	}
	if (frnt == -1)
		frnt = 0;
}
template<typename T>
T CircularQueue<T>::deQueue()
{
	T element;
	if (isEmpty())
	{
		cout << "\nQueue is Empty!";
	}
	else
	{
		element = queue[frnt];
		if (frnt == rear)
		{
			frnt = -1;
			rear = -1;
		}
		else
		{
			frnt = (frnt + 1) % size;
		}
	}
	return element;
}
template<typename T>
T CircularQueue<T>::front()
{
	T element;
	if (isEmpty())
	{
		cout << "\nQueue is Empty!";
	}
	else
	{
		element = queue[frnt];
	}
	return element;
}
template<typename T>
bool CircularQueue<T>::isFull()
{
	return frnt == (rear + 1) % size;
}
template<typename T>
bool CircularQueue<T>::isEmpty()
{
	return (frnt == -1 && rear == -1);
}
template <typename T>
int CircularQueue<T>::getSize()
{
	return rear + 1;
}