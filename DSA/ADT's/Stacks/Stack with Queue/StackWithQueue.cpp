#include"StackWithQueue.h"
#include<iostream>
using namespace std;
Stack::Stack():q(100)
{
}
void Stack::push(int x)
{
	if (q.isFull())
	{
		cout << "\nStack is Full!";
		return;
	}
	q.enQueue(x);
	for (int i = 0; i < q.getSize() - 1; i++)
	{
		q.enQueue(q.front());
		q.deQueue();
	}
}
int Stack::pop()
{
	return q.deQueue();
}
int Stack::top()
{
	return q.front();
}
bool Stack::empty()
{
	return q.isEmpty();
}