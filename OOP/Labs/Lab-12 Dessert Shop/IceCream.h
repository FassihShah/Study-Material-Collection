#ifndef ICE_CREAM_H
#define ICE_CREAM_H
#include"DessertItem.h"
class IceCream :public DessertItem
{
	int cost;
public:
	IceCream(int c, String n);
	double getCost() const;
	DessertItem& clone() const;
};
#endif