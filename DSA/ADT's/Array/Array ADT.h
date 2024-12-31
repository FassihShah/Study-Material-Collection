#ifndef ARRAY_H
#define ARRAY_H
template<typename T>
class Array
{
	T* data;
	int size;
	int capacity;
	void copyArray(T* const dest, const T* const src, int cap);
	void swap(T& a, T& b);
public:
	Array();
	Array(int);
	~Array();
	int getSize() const;
	void reSize(int newCapacity);
	T& operator[](int index) const;
	void insert(int index, const T& value);
	void remove(int index);
	void sort();
	void display();
};
#endif