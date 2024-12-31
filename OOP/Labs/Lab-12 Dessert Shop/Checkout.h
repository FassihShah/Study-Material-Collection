#ifndef CHECKOUT_H
#define CHECKOUT_H
#include"DessertItem.h"
#include"Array.h"
class Checkout
{
	DessertItem** list;
	Array countPerItem;
	int itemsCount;
	int listCapacity;
	void reSize(int);
public:
	Checkout();
	~Checkout();
	void clear();
	void enterItem(const DessertItem& item, int cnt = 1);
	String toString();
	double totalCost();
	double totalTax();
};
#endif