#include"Checkout.h"
#include"DessertShoppe.h"
#include<iomanip>
Checkout::Checkout():countPerItem(10)
{
	list = new DessertItem*[10];
	listCapacity = 10;
	itemsCount = 0;
}
void Checkout::enterItem(const DessertItem& item, int cnt)
{
	if (itemsCount == listCapacity)
		reSize(listCapacity + 10);
	list[itemsCount] = &item.clone();
	countPerItem[itemsCount] = cnt;
	itemsCount++;
}
Checkout::~Checkout()
{
	for (int i = 0; i < itemsCount; i++)
	{
		delete list[i];
	}
	delete[] list;
	list = nullptr;
	listCapacity = 0;
	itemsCount = 0;
	countPerItem.~Array();
}
void Checkout::clear()
{
	this->~Checkout();
}
void Checkout::reSize(int r)
{
	DessertItem** newData = new DessertItem* [r];
	for (int i = 0; i < itemsCount; i++)
	{
		newData[i] = &list[i]->clone();
	}
	for (int i = 0; i < itemsCount; i++)
	{
		delete list[i];
	}
	delete[] list;
	countPerItem.reSize(r);
	listCapacity = r;
	list = newData;
}
String Checkout::toString()
{
	String s = "   ";
	s += DessertShoppe::getStoreName();
	s += "\n----------------------------------------\n";
	double cost = 0;
	for (int i = 0; i < itemsCount; i++)
	{
		int c = 0, w = DessertShoppe::getMaxItemNameWidth();
		String name = list[i]->getName();
		s += "\n";
		while (c < w && c < name.getLenght())
		{
			s += name[c];
			c++;
		}
		String price = DessertShoppe::centsToDollars(list[i]->getCost() * countPerItem[i]);
		int cnt = c + price.getLenght();
		while (cnt < 40)
		{
			s += ".";
			cnt++;
		}
		s += price + " = ";
		price = (long long int)countPerItem[i];
		cost += list[i]->getCost() * countPerItem[i];
		s += price + " * " + DessertShoppe::centsToDollars(list[i]->getCost());
		while (c < name.getLenght())
		{
			cnt = 0;
			s += "\n";
			while (cnt < w && c < name.getLenght())
			{
				s += name[c];
				cnt++;
				c++;
			}
		}
	}
	s += "\n";
	String t;
	t = DessertShoppe::centsToDollars(totalTax());
	s += "Tax";
	int i = 3 + t.getLenght();
	while (i < 40)
	{
		s += "~";
		i++;
	}
	s += t;
	t = DessertShoppe::centsToDollars(totalTax() + cost);
	s += "\nTotal Cost";
	i = 10 + t.getLenght();
	while (i < 40)
	{
		s += "~";
		i++;
	}
	s += t;
	return s;
}
double Checkout::totalCost()
{
	double cost = 0;
	for (int i = 0; i < itemsCount; i++)
	{
		cost = cost + (list[i]->getCost() * countPerItem[i]);
	}
	return cost;
}
double Checkout::totalTax()
{
	double tax = 0;
	for (int i = 0; i < itemsCount; i++)
	{
		tax = tax + (list[i]->getTax() * countPerItem[i]);
	}
	return tax;
}