#include"OvernightPackage.h"
OvernightPackage::OvernightPackage(Person s, Person r, double w, double c, double f) :Package(s, r, w, c)
{
	feePerOunce = (f >= 0 ? f : 0);
}
double OvernightPackage::calculateCost()
{
	return (Package::getWeight()*(Package::getCost()+feePerOunce));
}