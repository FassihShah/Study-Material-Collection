#ifndef LLIST_H
#define LLIST_H
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
class LList
{
	Node<T>* head;
	Node<T>* tail;
public:
	LList();
	bool isEmpty();
	void addToHead(T);
	void addToTail(T);
	T deleteFromHead();
	T deleteFromTail();
	void print();
};
template class LList<int>;
template class Node<int>;
#endif