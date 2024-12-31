#include<iostream>
#include"LList.h"
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
LList<T>::LList()
{
	head = nullptr;
	tail = nullptr;
}
template<typename T>
bool LList<T>::isEmpty()
{
	return head == nullptr;
}
template<typename T>
void LList<T>::addToHead(T val)
{
	head = new Node<T>(val, head);
	if (tail == nullptr)
		tail = head;
}
template<typename T>
void LList<T>::addToTail(T val)
{
	if (tail == nullptr)
	{
		tail = new Node<T>(val);
		head = tail;
	}
	else
	{
		tail->next = new Node<T>(val);
		tail = tail->next;
	}
}
template<typename T>
T LList<T>::deleteFromHead()
{
	T val = head->data;
	Node<T>* temp = head;
	if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = head->next;
		delete temp;
	}
	return val;
}
template<typename T>
T LList<T>::deleteFromTail()
{
	T val = tail->data;
	Node<T>* temp = tail;
	if (head == tail)
	{
		delete tail;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node<T>* current = head;
		while (current->next != tail)
		{
			current = current->next;
		}
		tail = current;
		tail->next = nullptr;
		delete temp;
	}
	return val;
}
template<typename T>
void LList<T>::print()
{
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}