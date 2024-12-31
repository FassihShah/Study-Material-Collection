#include<iostream>
#include"Queue.h"
using namespace std;
template<typename T>
Queue<T>::Queue(int s)
{
	size = s;
	queue = new T[size];
	rear = -1;
	frnt = -1;
}
template<typename T>
void Queue<T>::enQueue(T val)
{
	if (isFull())
	{
		cout << "\nQueue is Full!";
		return;
	}
	else
	{
		rear++;
		queue[rear] = val;
	}
	if (frnt == -1)
		frnt = 0;
}
template<typename T>
T Queue<T>::deQueue()
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
			for (int i = 0; i < rear; i++)
			{
				queue[i] = queue[i + 1];
			}
			rear--;
		}
	}
	return element;
}
template<typename T>
T Queue<T>::front()
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
bool Queue<T>::isFull()
{
	return (rear == size - 1);
}
template<typename T>
bool Queue<T>::isEmpty()
{
	return (frnt == -1 && rear == -1);
}
template <typename T>
int Queue<T>::getSize()
{
	return rear + 1;
}