#include"Sundae.h"
Sundae::Sundae(int topping, int iceCost, String n):IceCream(iceCost,n)
{
	toppingCost = (topping > 0 ? topping : 0);
}
double Sundae::getCost() const
{
	return toppingCost + IceCream::getCost();
}
DessertItem& Sundae::clone() const
{
	return *new Sundae(toppingCost,IceCream::getCost(), IceCream::getName());
}