#ifndef DESSERT_SHOPPE_H
#define DESSERT_SHOPPE_H
#include"String.h"
class DessertShoppe
{
	static double _TAX_RATE;
	static const String _STORE_NAME;
	static const int _MAX_ITEM_NAME_WIDTH;
public:
	static String centsToDollars(int cents);
	static double getTaxRate();
	static const String getStoreName();
	static const int getMaxItemNameWidth();
	static void setTaxRate(double);
};
#endif