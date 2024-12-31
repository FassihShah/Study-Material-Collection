#include"TwoDayPackage.h"
TwoDayPackage::TwoDayPackage(Person s, Person r, double w, double c, double f):Package(s,r,w,c)
{
	flatFee = (f >= 0 ? f : 0);
}
double TwoDayPackage::calculateCost()
{
	return (Package::calculateCost() + flatFee);
}