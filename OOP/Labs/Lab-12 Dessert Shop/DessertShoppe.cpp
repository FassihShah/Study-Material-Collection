#include"DessertShoppe.h"
const String DessertShoppe:: _STORE_NAME = "Fall-22 : CS & SE : Dessert Shoppe";
const int DessertShoppe::_MAX_ITEM_NAME_WIDTH = 24;
double DessertShoppe::_TAX_RATE = 0;
String DessertShoppe::centsToDollars(int cents)
{
	String s = "";
	if (cents < 0)
	{
		s += "-";
		cents *= -1;
	}
	int dollars = cents / 100;
	cents = cents % 100;
	String t;
	t = (long long int)dollars;
	if (dollars > 0)
		s += t;
	s += ".";
	if (cents < 10)
		s += "0";
	t = (long long int)cents;
	s += t;
	return s;
}
double DessertShoppe::getTaxRate()
{
	return _TAX_RATE;
}
const String DessertShoppe::getStoreName()
{
	return _STORE_NAME;
}
const int DessertShoppe::getMaxItemNameWidth()
{
	return _MAX_ITEM_NAME_WIDTH;
}
void DessertShoppe::setTaxRate(double t)
{
	_TAX_RATE = t;
}