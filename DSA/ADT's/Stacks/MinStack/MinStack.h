#ifndef MIN_STACK_H
#define MIN_STACK_H
#include"Stack_Implementation.cpp"
class MinStack
{
	Stack<int> stack;
	Stack<int> min;
public:
	MinStack();
	void push(int val);
	void pop();
	int top();
	int getMin();
};
#endif