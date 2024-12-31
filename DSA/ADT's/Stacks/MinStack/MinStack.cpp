#include"MinStack.h"
MinStack::MinStack():stack(100),min(100)
{
}
void MinStack::push(int val)
{
	if (min.top() == -1 || min.top() > val)
		min.push(val);
	stack.push(val);
}
void MinStack::pop()
{
	if (stack.top() == min.top())
		min.pop();
	stack.pop();
}
int MinStack::top()
{
	return stack.top();
}
int MinStack::getMin()
{
	if (stack.isEmpty())
	{
		cout << "Stack is Empty!";
		return -1;
	}
	return min.top();
}