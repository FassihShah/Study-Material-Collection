#ifndef GENERIC_DICTIONARY_H
#define GENERIC_DICTIONARY_H
#include"DictionaryPair_Implementation.cpp"
template<typename T, typename R>
class GenericDictionary
{
	DictionaryPair<T, R>* data;
	int noOfItems;
	int capacity;
	void reSize();
public:
	GenericDictionary();
	void addPair(T k, R v);
	R getValue(T k);
	void print();
	~GenericDictionary();
	bool isFull();
	bool isEmpty();
};
#endif