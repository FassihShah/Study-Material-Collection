#include"Stack.h"
template <typename T>
Stack<T>::Stack(int cap)
{
	if (cap < 0)
	{
		cout << "Capacity should be greater than 0";
		return;
	}
	stack = new T[2];
	capacity = cap;
	topIndex = -1;
}
template<typename T>
bool Stack<T>::isEmpty()
{
	return (topIndex == -1);
}
template<typename T>
bool Stack<T>::isFull()
{
	return (topIndex == capacity - 1);
}
template<typename T>
T Stack<T>::top()
{
	if (isEmpty())
		return -1;
	else
		return stack[topIndex];
}
template<typename T>
T Stack<T>::pop()
{
	if (isEmpty())
		return -1;
	else
		topIndex--;
		return stack[topIndex + 1];
}
template<typename T>
void Stack<T>::push(T x)
{
	if (isFull())
	{
		cout << "Stack is Full!";
		return;
	}
	else
	{
		topIndex++;
		stack[topIndex] = x;
	}
}