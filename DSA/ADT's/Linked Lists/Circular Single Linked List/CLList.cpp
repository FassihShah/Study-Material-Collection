#include<iostream>
#include"CLList.h"
using namespace std;
template<typename T>
Node<T>::Node()
{
	next = nullptr;
}
template<typename T>
Node<T>::Node(T d, Node<T>* n)
{
	data = d;
	next = n;
}
template<typename T>
T Node<T>::getData()
{
	return data;
}
template<typename T>
CLList<T>::CLList()
{
	tail = nullptr;
}
template<typename T>
bool CLList<T>::isEmpty()
{
	return tail == nullptr;
}
template<typename T>
void CLList<T>::addToHead(T val)
{
	if (tail == nullptr)
	{
		tail = new Node<T>(val);
		tail->next = tail;
	}
	else
	{
		tail->next = new Node<T>(val, tail->next);
	}
}
template<typename T>
void CLList<T>::addToTail(T val)
{
	if (tail == nullptr)
	{
		tail = new Node<T>(val);
		tail->next = tail;
	}
	else
	{
		tail->next = new Node<T>(val, tail->next);
		tail = tail->next;
	}
}
template<typename T>
T CLList<T>::deleteFromHead()
{
	int val = tail->next->data;
	if (tail->next == tail)
	{
		delete tail;
		tail = nullptr;
	}
	else
	{
		Node<T>* temp = tail->next->next;
		delete tail->next;
		tail->next = temp;
	}
	return val;
}
template<typename T>
T CLList<T>::deleteFromTail()
{
	int val = tail->data;
	if (tail->next == tail)
	{
		delete tail;
		tail = nullptr;
	}
	else
	{
		Node<T>* temp = tail->next;
		while (temp->next != tail)
		{
			temp = temp->next;
		}
		temp->next = tail->next;
		delete tail;
		tail = temp;
	}
	return val;
}
template<typename T>
void CLList<T>::print()
{
	Node<T>* temp = tail->next;
	while (temp != tail)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data;
}