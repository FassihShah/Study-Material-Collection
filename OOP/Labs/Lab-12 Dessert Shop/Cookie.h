#ifndef COOKIE_H
#define COOKIE_H
#include"DessertItem.h"
class Cookie :public DessertItem
{
	int number;
	double pricePerDozen;
public:
	Cookie(int n, double p, String s);
	double getCost() const;
	DessertItem& clone() const;
};

#endif