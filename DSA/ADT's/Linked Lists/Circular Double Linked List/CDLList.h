#ifndef CDLLIST_H
#define CDLLIST_H
template<typename T>
class DNode
{
public:
	T data;
	DNode<T>* next;
	DNode<T>* prev;
	DNode();
	DNode(T, DNode<T>* = nullptr, DNode<T>* = nullptr);
	T getData();
};
template<typename T>
class CDLList
{
	DNode<T>* tail;
public:
	CDLList();
	bool isEmpty();
	void addToHead(T);
	void addToTail(T);
	T deleteFromHead();
	T deleteFromTail();
	void print();
};
template class CDLList<int>;
template class DNode<int>;
#endif