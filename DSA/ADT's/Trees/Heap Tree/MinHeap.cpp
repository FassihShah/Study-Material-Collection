#include<iostream>
#include"MinHeap.h"
using namespace std;
MinHeap::MinHeap(int cap)
{
    capacity = cap;
    size = 0;
    heap = new int[cap];
}
MinHeap::~MinHeap()
{
    delete[] heap;
    heap = nullptr;
    size = 0;
}
void MinHeap::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
int MinHeap::parent(int i)
{
    return (i - 1) / 2;
}
int MinHeap::left(int i)
{
    return 2 * i + 1;
}
int MinHeap::right(int i)
{
    return 2 * i + 2;
}
void MinHeap::heapifyUp(int index)
{
    if (index == 0)
        return;
    int parentIndex = parent(index);
    if (heap[index] < heap[parentIndex])
    {
        swap(heap[index], heap[parentIndex]);
        heapifyUp(parentIndex);
    }
}
void MinHeap::heapifyDown(int index)
{
    int leftChild = left(index);
    int rightChild = right(index);
    int smallest = index;
    if (leftChild < size && heap[leftChild] < heap[smallest])
    {
        smallest = leftChild;
    }
    if (rightChild < size && heap[rightChild] < heap[smallest])
    {
        smallest = rightChild;
    }
    if (smallest != index)
    {
        swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}
bool MinHeap::isEmpty() const
{
    return size == 0;
}
int MinHeap::getSize() const
{
    return size;
}
int MinHeap::peek() const
{
    if (size == 0)
    {
        cout << "\nTree is empty!";
        exit(0);
    }
    return heap[0];
}
void MinHeap::enqueue(int t)
{
    if (size == capacity)
    {
        cout << "Queue is Full!";
        return;
    }
    heap[size] = t;
    heapifyUp(size);
    size++;
}
int MinHeap::dequeue()
{
    if (size == 0)
    {
        cout << "\nTree is empty!";
        exit(0);
    }
    int minValue = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return minValue;
}