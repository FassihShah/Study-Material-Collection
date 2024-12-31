#include"Cookie.h"
Cookie::Cookie(int n, double p, String s):DessertItem(s)
{
	number = (n > 0 ? n : 0);
	pricePerDozen = (p > 0 ? p : 0);
}
double Cookie::getCost() const
{
	return ((float)number / 12) * pricePerDozen;
}
DessertItem& Cookie::clone() const
{
	return *new Cookie(number,pricePerDozen, DessertItem::getName());
}