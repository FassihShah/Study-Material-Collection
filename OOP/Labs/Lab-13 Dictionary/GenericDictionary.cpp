#include"GenericDictionary.h"
#include<iostream>
using namespace std;
template<typename T, typename R>
GenericDictionary<T, R>::GenericDictionary()
{
	capacity = 0;
	data = nullptr;
	noOfItems = 0;
}
template<typename T, typename R>
void GenericDictionary<T, R>::addPair(T k, R v)
{
	if (isFull())
	{
		reSize();
	}
	for (int i = 0; i < noOfItems; i++)
	{
		if (data[i].getKey() == k)
		{
			data[i].setValue(v);
			return;
		}
	}
	data[noOfItems].setKey(k);
	data[noOfItems].setValue(v);
	noOfItems++;
}
template<typename T, typename R>
R GenericDictionary<T, R>::getValue(T k)
{
	for (int i = 0; i < noOfItems; i++)
	{
		if (data[i].getKey() == k)
		{
			return data[i].getValue();
		}
	}
	exit(0);
}
template<typename T, typename R>
void GenericDictionary<T, R>::print()
{
	if (isEmpty())
		return;
	for (int i = 0; i < noOfItems; i++)
	{
		cout << data[i].getKey() << "  " << data[i].getValue();
		cout << "\n";
	}
}
template<typename T, typename R>
GenericDictionary<T, R>::~GenericDictionary()
{
	delete[] data;
	data = nullptr;
	capacity = 0;
	noOfItems = 0;
}
template<typename T, typename R>
bool GenericDictionary<T, R>::isFull()
{
	if (capacity == noOfItems)
		return true;
	return false;
}
template<typename T, typename R>
bool GenericDictionary<T, R>::isEmpty()
{
	if (noOfItems == 0)
		return true;
	return false;
}
template<typename T, typename R>
void GenericDictionary<T, R>::reSize()
{
	capacity = (capacity == 0 ? 1 : capacity * 2);
	DictionaryPair<T, R>* newData = new DictionaryPair<T, R>[capacity];
	if (!isEmpty())
	{
		for (int i = 0; i < noOfItems; i++)
		{
			newData[i] = data[i];
		}
	}
	delete[] data;
	data = newData;
}