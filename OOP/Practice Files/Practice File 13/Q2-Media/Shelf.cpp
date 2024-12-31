#include"Shelf.h"
Shelf::Shelf(int s)
{
	maxSize = s;
	currSize = 0;
	items = new Media * [s];
}
void Shelf::insert(Media* o)
{
	items[currSize] = o;
	currSize++;
}
void Shelf::displayContents()
{
	for (int i = 0; i < currSize; i++)
	{
		items[i]->display();
	}
}
Shelf::~Shelf()
{
	for (int i = 0; i < currSize; i++)
	{
		delete items[i];
	}
	delete[] items;
	items = nullptr;
	currSize = 0;
}