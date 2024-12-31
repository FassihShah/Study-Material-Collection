#include<iostream>
#include"DLList.h"
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
DLList<T>::DLList()
{
	head = nullptr;
	tail = nullptr;
}
template<typename T>
bool DLList<T>::isEmpty()
{
	return head == nullptr;
}
template<typename T>
void DLList<T>::addToHead(T val)
{
	if (head == nullptr)
	{
		head = new DNode<T>(val);
		tail = head;
	}
	else
	{
		head->prev = new DNode<T>(val, head);
		head = head->prev;
	}
}
template<typename T>
void DLList<T>::addToTail(T val)
{
	if (head == 0)
	{
		head = new DNode<T>(val);
		tail = head;
	}
	else
	{
		tail = new DNode<T>(val, nullptr, tail);
		tail->prev->next = tail;
	}
}
template<typename T>
T DLList<T>::deleteFromHead()
{
	T val = head->data;
	if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}
	return val;
}
template<typename T>
T DLList<T>::deleteFromTail()
{
	T val = tail->data;
	if (head == tail)
	{
		delete head;
		tail = nullptr;
		head = nullptr;
	}
	else
	{
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
	return val;
}
template<typename T>
void DLList<T>::print()
{
	DNode<T>* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}