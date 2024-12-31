#ifndef STACKQ_H
#define STACKQ_H
#include"Queue.h"
class Stack
{
	Queue<int> q;
public:
	Stack(); 
	void push(int x);
	int pop();
	int top(); 
	bool empty(); 
};
#endif
