#ifndef SHELF_H
#define SHELF_H
#include"Book.h"
#include"Magazine.h"
#include"CD.h"
class Shelf
{
	Media** items;
	int maxSize;
	int currSize;
public:
	Shelf(int);
	void insert(Media*);
	void displayContents();
	~Shelf();
};
#endif