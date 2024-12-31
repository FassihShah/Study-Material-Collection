#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;
template <typename T>
class Stack
{
	T* stack;
	int capacity;
	int topIndex;
public:
	Stack(int);
	bool isEmpty();
	bool isFull();
	T top();
	T pop();
	void push(T);
};
#endif