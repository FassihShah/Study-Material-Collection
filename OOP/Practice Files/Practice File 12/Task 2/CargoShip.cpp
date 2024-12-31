#include"CargoShip.h"
CargoShip::CargoShip(String n, String y, int c):Ship(n,y)
{
	setCapacity(c);
}
void CargoShip::setCapacity(int c)
{
	cargoCapacity = (c >= 0 ? c : 0);
}
int CargoShip::getCapacity()
{
	return cargoCapacity;
}
void CargoShip::print()
{
	cout << "\nName : " << getName() << "\nCargo Capacity : " << cargoCapacity;
}