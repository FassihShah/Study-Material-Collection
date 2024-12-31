#include"DessertItem.h"
#include"DessertShoppe.h"
DessertItem::DessertItem(String s):name(s)
{
}
String DessertItem::getName() const
{
	return name;
}
double DessertItem::getTax() const
{
	return ((float)DessertShoppe::getTaxRate()/100) * (float)getCost();
}