#include<iostream>
#include"Array ADT.h"
using namespace std;
template<typename T>
void Array<T>::swap(T& a, T& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
template<typename T>
void Array<T>::copyArray(T* const dest, const T* const src, int cap)
{
	if (src == nullptr)
	{
		return;
	}
	for (int i = 0; i < cap; i++)
	{
		dest[i] = src[i];
	}
}
template<typename T>
Array<T>::Array()
{
	data = nullptr;
	size = 0;
	capacity = 0;
}
template<typename T>
Array<T>::Array(int s)
{
	capacity = s;
	data = new T[s];
	size = 0;
}
template<typename T>
Array<T>::~Array()
{
	if (capacity == 0)
	{
		return;
	}
	delete[]data;
	data = nullptr;
	size = 0;
	capacity = 0;
}
template<typename T>
void Array<T>::reSize(int newCapacity)
{
	if (newCapacity <= 0)
	{
		this->~Array();
		return;
	}
	T* temp = new T[newCapacity];
	if (newCapacity >= capacity)
	{
		copyArray(temp, data, size);
	}
	else
	{
		copyArray(temp, data, newCapacity);
	}
	this->~Array();
	size = newCapacity;
	data = temp;
	capacity = newCapacity;
}
template<typename T>
int Array<T>::getSize() const
{
	return size;
}
template<typename T>
T& Array<T>::operator[](int index) const
{
	if (index >=0 && index < size)
	{
		return data[index];
	}
	exit(0);
}
template<typename T>
void Array<T>::insert(int index, const T& value)
{
	if (size == capacity)
		reSize(capacity * 2 + 1);
	for (int i = size - 1; i > index; i--)
	{
		data[i] = data[i + 1];
	}
	data[index] = value;
	size++;
}
template<typename T>
void Array<T>::display()
{
	if (size == 0)
		return;
	cout << "{";
	for (int i = 0; i < size - 1; i++)
	{
		cout << data[i] << ", ";
	}
	cout << data[size - 1] << "}";
}
template<typename T>
void Array<T>::remove(int index)
{
	if (index >= size)
		return;
	for (int i = index; i < size - 1; i++)
	{
		data[i] = data[i + 1];
	}
	size--;
}
template<typename T>
void Array<T>::sort()
{
	int i = size - 1;
	while (i >= 0)
	{
		int j = 0;
		while (j < i)
		{
			if (data[j] > data[j + 1])
			{
				swap(data[j], data[j + 1]);
			}
			j++;
		}
		i--;
	}
}