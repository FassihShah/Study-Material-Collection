#ifndef PACKAGE_H
#define PACKAGE_H
#include"Person.h"
class Package
{
	Person sender;
	Person recipient;
	double weight;
	double costPerOunce;
public:
	Package(Person, Person, double, double);
	double calculateCost();
	double getWeight();
	double getCost();
};

#endif
