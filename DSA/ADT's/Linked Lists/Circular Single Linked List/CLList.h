#ifndef CLLIST_H
#define CLLIST_H
template<typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node();
	Node(T, Node<T>* = nullptr);
	T getData();
};
template<typename T>
class CLList
{
	Node<T>* tail;
public:
	CLList();
	bool isEmpty();
	void addToHead(T);
	void addToTail(T);
	T deleteFromHead();
	T deleteFromTail();
	void print();
};
template class CLList<int>;
template class Node<int>;
#endif