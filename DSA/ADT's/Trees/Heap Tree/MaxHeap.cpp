#include<iostream>
#include"HeapTree.h"
using namespace std;
HeapTree::HeapTree(int cap)
{
	capacity = cap;
	size = 0;
	heap = new int[cap];
}
HeapTree::~HeapTree()
{
	delete[] heap;
	heap = nullptr;
	size = 0;
}
void HeapTree::swap(int& a, int& b)
{
   int temp = a;
   a = b;
   b = temp;
}
void HeapTree::reSize()
{
	int* newHeap = new int[capacity * 2];
	for (int i = 0; i < size; i++)
	{
		newHeap[i] = heap[i];
	}
	delete[] heap;
	heap = newHeap;
	capacity *= 2;
}
void HeapTree::heapifyUp(int index)
{
    if (index == 0)
        return;
    int parentIndex = (index - 1) / 2;
    if (heap[index] > heap[parentIndex])
    {
        swap(heap[index], heap[parentIndex]);
        heapifyUp(parentIndex);
    }
}

void HeapTree::heapifyDown(int index)
{
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;
    if (leftChild < size && heap[leftChild] > heap[largest])
    {
        largest = leftChild;
    }
    if (rightChild < size && heap[rightChild] > heap[largest])
    {
        largest = rightChild;
    }
    if (largest != index)
    {
        swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}
void HeapTree::insert(int val)
{
    if (size == capacity)
    {
        reSize();
    }
    heap[size] = val;
    heapifyUp(size);
    size++;
}
int HeapTree::deleteMax()
{
    if (size == 0)
    {
        cout << "\nTree is empty!";
        return -1;
    }
    int maxValue = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return maxValue;
}
void HeapTree::display()
{
    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
    }
}