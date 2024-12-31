#ifndef LLIST_H
#define LLIST_H
template<typename T>
class DNode
{
public:
	T data;
	DNode<T>* next;
	DNode<T>* prev;
	DNode();
	DNode(T, DNode<T>* = nullptr, DNode<T> * = nullptr);
	T getData();
};
template<typename T>
class DLList
{
public:
	DNode<T>* head;
	DNode<T>* tail;
	DLList();
	bool isEmpty();
	void addToHead(T);
	void addToTail(T);
	T deleteFromHead();
	T deleteFromTail();
	void print();
};
template class DLList<int>;
template class DNode<int>;
#endif