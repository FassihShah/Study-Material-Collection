#include<iostream>
#include"CDLList.h"
using namespace std;
template<typename T>
DNode<T>::DNode()
{
	next = nullptr;
	prev = nullptr;
}
template<typename T>
DNode<T>::DNode(T d, DNode<T>* n, DNode<T>* p)
{
	data = d;
	next = n;
	prev = p;
}
template<typename T>
T DNode<T>::getData()
{
	return data;
}
template<typename T>
CDLList<T>::CDLList()
{
	tail = nullptr;
}
template<typename T>
bool CDLList<T>::isEmpty()
{
	return tail == nullptr;
}
template<typename T>
void CDLList<T>::addToHead(T val)
{
	if (tail == nullptr)
	{
		tail = new DNode<T>(val);
		tail->next = tail;
		tail->prev = tail;
	}
	else
	{
		tail->next = new DNode<T>(val, tail->next, tail);
		tail->next->next->prev = tail->next;
	}
}
template<typename T>
void CDLList<T>::addToTail(T val)
{
	if (tail == nullptr)
	{
		tail = new DNode<T>(val);
		tail->next = tail;
		tail->prev = tail;
	}
	else
	{
		tail->next = new DNode<T>(val, tail->next, tail);
		tail = tail->next;
		tail->next->prev = tail;
	}
}
template<typename T>
T CDLList<T>::deleteFromHead()
{
	int val = tail->next->data;
	if (tail->next == tail)
	{
		delete tail;
		tail = nullptr;
	}
	else
	{
		DNode<T>* temp = tail->next->next;
		delete tail->next;
		tail->next = temp;
		tail->next->prev = tail;
	}
	return val;
}
template<typename T>
T CDLList<T>::deleteFromTail()
{
	int val = tail->data;
	if (tail->next == tail)
	{
		delete tail;
		tail = nullptr;
	}
	else
	{
		DNode<T>* temp = tail->prev;
		tail->prev->next = tail->next;
		tail->next->prev = tail->prev;
		delete tail;
		tail = temp;
	}
	return val;
}
template<typename T>
void CDLList<T>::print()
{
	DNode<T>* temp = tail->next;
	while (temp != tail)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data;
}