#ifndef OVERNIGHT_PACKAGE_H
#define OVERNIGHT_PACKAGE_H
#include"Package.h"
class OvernightPackage :public Package
{
	double feePerOunce;
public:
	OvernightPackage(Person, Person, double, double, double);
	double calculateCost();
};
#endif