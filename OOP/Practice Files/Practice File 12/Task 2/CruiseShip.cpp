#include"CruiseShip.h"
CruiseShip::CruiseShip(String n, String y, int p):Ship(n,y)
{
	setPassengers(p);
}
void CruiseShip::setPassengers(int p)
{
	maxPassengers = (p >= 0 ? p : 0);
}
int CruiseShip::getPassengers()
{
	return maxPassengers;
}
void CruiseShip::print()
{
	cout << "\nName : " << getName() << "\nBuilt Year : " << getYear() << "\nMaximum No. of Passengers : " << maxPassengers;
}