#ifndef SUNDAE_H
#define SUNDAE_H
#include"IceCream.h"
class Sundae :public IceCream
{
	int toppingCost;
public:
	Sundae(int topping, int iceCost, String n);
	double getCost() const;
	DessertItem& clone() const;
};
#endif