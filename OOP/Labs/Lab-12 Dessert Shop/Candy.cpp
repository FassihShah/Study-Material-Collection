#include"Candy.h"
Candy::Candy(double w, double p, String n) :DessertItem(n)
{
	weight = (w > 0 ? w : 0);
	pricePerPound = (p > 0 ? p : 0);
}
double Candy::getCost() const
{
	return weight * pricePerPound;
}
DessertItem& Candy::clone() const
{
	return *new Candy(weight,pricePerPound, DessertItem::getName());
}