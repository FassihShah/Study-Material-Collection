#include"IceCream.h"
IceCream::IceCream(int c, String n):DessertItem(n)
{
	cost = (c > 0 ? c : 0);
}
double IceCream::getCost() const
{
	return cost;
}
DessertItem& IceCream::clone() const
{
	return *new IceCream(cost, DessertItem::getName());
}