#ifndef CANDY_H
#define CANDY_H
#include"DessertItem.h"
class Candy :public DessertItem
{
	double weight;
	double pricePerPound;
public:
	Candy(double w, double p, String n);
	double getCost() const;
	DessertItem& clone() const;
};

#endif