#include<iostream>
#include"CDLL.h"
using namespace std;
template<typename T>
Node<T>::Node()
{
	next = nullptr;
	prev = nullptr;
}
template<typename T>
Node<T>::Node(T val)
{
	data = val;
	next = nullptr;
	prev = nullptr;
}
template<typename T>
Node<T>::Node(T val, Node<T>* n, Node<T>* p)
{
	data = val;
	next = n;
	prev = p;
}
template<typename T>
CDLL<T>::CDLL()
{
	head = nullptr;
}
template<typename T>
CDLL<T>::~CDLL()
{
	Node<T>* temp = head;
	while (temp->next != head)
	{
		temp = temp->next;
		delete temp->prev;
	}
	delete temp;
	head = nullptr;
}
template<typename T>
CDLL<T>::CDLL(const CDLL<T>& ref):CDLL()
{
	if (ref.head == nullptr)
		return;
	Node<T>* temp = ref.head;
	do
	{
		insertAtTail(temp->data);
		temp = temp->next;
	} 
	while (temp != ref.head);
}
template<typename T>
void CDLL<T>::insertAtHead(T val)
{
	if (head == nullptr)
	{
		head = new Node<T>(val);
		head->next = head;
		head->prev = head;
	}
	else
	{
		head->prev = new Node<T>(val, head, head->prev);
		head = head->prev;
		head->prev->next = head;
	}
}
template<typename T>
void CDLL<T>::insertAtTail(T val)
{
	if (head == nullptr)
	{
		head = new Node<T>(val);
		head->next = head;
		head->prev = head;
	}
	else
	{
		head->prev = new Node<T>(val, head, head->prev);
		head->prev->prev->next = head->prev;
	}
}
template<typename T>
void CDLL<T>::removeAtHead()
{
	if (head == nullptr)
		return;
	if (head->next == head)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		Node<T>* temp = head->next;
		head->next->prev = head->prev;
		head->prev->next = head->next;
		delete head;
		head = temp;
	}
}
template<typename T>
void CDLL<T>::removeAtTail()
{
	if (head == nullptr)
		return;
	if (head->next == head)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		Node<T>* temp = head->prev->prev;
		delete head->prev;
		head->prev = temp;
		head->prev->next = head;
	}
}
template<typename T>
void CDLL<T>::insertAfter(T key, T val)
{
	if (head == nullptr)
		return;
	Node<T>* temp = head;
	bool status = false;
	do
	{
		if (temp->data == key && temp == head->prev)
		{
			insertAtTail(val);
			status = true;
		}
		else if (temp->data == key)
		{
			temp->next = new Node<T>(val, temp->next, temp);
			temp->next->next->prev = temp->next;
			status = true;
		}
		temp = temp->next;
	} 
	while (temp != head && !status);
}
template<typename T>
void CDLL<T>::insertBefore(T key, T val)
{
	if (head == nullptr)
		return;
	Node<T>* temp = head;
	bool status = false;
	do
	{
		if (temp->data == key && temp == head)
		{
			insertAtHead(val);
			status = true;
		}
		else if (temp->data == key)
		{
			temp->prev = new Node<T>(val, temp, temp->prev);
			temp->prev->prev->next = temp->prev;
			status = true;
		}
		temp = temp->next;
	} 
	while (temp != head && !status);
}
template<typename T>
void CDLL<T>::removeAfter(T key)
{
	if (head == nullptr)
		return;
	Node<T>* temp = head;
	bool status = false;
	do
	{
		if (temp->data == key && temp == head->prev)
		{
			removeAtHead();
			status = true;
		}
		else if (temp->data == key)
		{
			Node<T>* d = temp->next;
			temp->next = d->next;
			d->next->prev = temp;
			delete d;
			status = true;
		}
		temp = temp->next;
	} 
	while (temp != head && !status);
}
template<typename T>
void CDLL<T>::removeBefore(T key)
{
	if (head == nullptr)
		return;
	Node<T>* temp = head;
	bool status = false;
	do
	{
		if (temp->data == key && temp == head)
		{
			removeAtTail();
			status = true;
		}
		else if (temp->data == key)
		{
			Node<T>* d = temp->prev;
			temp->prev = d->prev;
			d->prev->next = temp;
			delete d;
			status = true;
		}
		temp = temp->next;
	} 
	while (temp != head && !status);
}
template<typename T>
void CDLL<T>::remove(T key)
{
	if (head == nullptr)
		return;
	Node<T>* temp = head;
	bool status = false;
	do
	{
		if (temp->data == key && temp == head)
		{
			removeAtHead();
			status = true;
		}
		else if (temp->data == key && temp == head->prev)
		{
			removeAtTail();
			status = true;
		}
		else if (temp->data == key)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			status = true;
		}
		else
		{
			temp = temp->next;
		}
	} while (temp != head && !status);
}
template<typename T>
void CDLL<T>::display()
{
	Node<T>* temp = head;
	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	} 
	while (temp != head);
}
template<typename T>
void CDLL<T>::rotateCircularDLL(int times)                 /// Task - 2
{
	if (times <= 0 || head == nullptr || head->next == head)
		return;
	Node<T>* temp = head;
	int length = 0;
	do
	{
		length++;
		temp = temp->next;
	} 
	while (temp != head);
	times = times % length;
	while (times != 0)
	{
		int val = head->prev->data;
		removeAtTail();
		insertAtHead(val);
		times--;
	}
}
template<typename T>
bool CDLL<T>::targetSum(int target)         /// Task - 3
{
	Node<T>* left = head;
	Node<T>* right = head->prev;
	while (left != right)
	{
		if (left->data + right->data < target)
		{
			left = left->next;
		}
		else if (left->data + right->data > target)
		{
			right = right->prev;
		}
		else
		{
			return true;
		}
	}
	return false;
}