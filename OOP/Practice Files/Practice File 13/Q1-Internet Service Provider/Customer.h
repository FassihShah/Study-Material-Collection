#ifndef CUSTOMER_H
#define CUSTOMER_H
#include"String.h"
class Customer
{
	int hours;
	String name;
	int spaceUsed;
protected:
	int getHours();
	int getSpaceUsed();
public:
	Customer(String, int = 0, int = 0);
	virtual double computeBill();
};
#endif