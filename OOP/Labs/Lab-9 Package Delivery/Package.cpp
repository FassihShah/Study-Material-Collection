#include"Package.h"
Package::Package(Person s, Person r, double w, double c):sender(s),recipient(r)
{
	weight = (w >= 0 ? w : 0);
	costPerOunce = (c >= 0 ? c : 0);
}
double Package::calculateCost()
{
	return weight * costPerOunce;
}
double Package::getWeight()
{
	return weight;
}
double Package::getCost()
{
	return costPerOunce;
}