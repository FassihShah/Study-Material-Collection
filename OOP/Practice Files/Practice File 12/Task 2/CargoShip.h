#pragma once
#include"Ship.h"
class CargoShip:public Ship
{
	int cargoCapacity;
public:
	CargoShip(String, String, int);
	void setCapacity(int);
	int getCapacity();
	void print();
};