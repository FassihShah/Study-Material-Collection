#ifndef CDLL_H
#define CDLL_H
template<typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
	Node();
	Node(T val);
	Node(T val, Node<T>* next, Node<T>* prev);
};
template<typename T>
class CDLL
{
	Node<T>* head;
public:
	CDLL();
	~CDLL(); 
	CDLL<T>(const CDLL<T>& ref); 
	void insertAtHead(T val);
	void insertAtTail(T val); 
	void insertAfter(T key, T val); 
	void insertBefore(T key, T val); 
	void removeAtHead(); 
	void removeAtTail(); 
	void removeAfter(T key); 
	void removeBefore(T key); 
	void remove(T key); 
	void display();
	void rotateCircularDLL(int times);
	bool targetSum(int target);
};
template class CDLL<int>;
template class Node<int>;
#endif